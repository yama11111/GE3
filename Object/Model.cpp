#include "Model.h"

using Object::Model;

DX::GPUResource::TextureManager* Model::texManager = nullptr;

void Model::StaticInit() 
{
	texManager = DX::GPUResource::TextureManager::GetInstance();
}

Model::Model() :
	vtIdx(DX::GPUResource::VertexIndex(
		{
			// 前
			{{ -1.0f, -1.0f, -1.0f }, {}, {0.0f, 1.0f}}, // 左下
			{{ -1.0f,  1.0f, -1.0f }, {}, {0.0f, 0.0f}}, // 左上
			{{  1.0f, -1.0f, -1.0f }, {}, {1.0f, 1.0f}}, // 右下
			{{  1.0f,  1.0f, -1.0f }, {}, {1.0f, 0.0f}}, // 右上

			// 後
			{{ -1.0f, -1.0f,  1.0f }, {}, {1.0f, 1.0f}}, // 左下
			{{ -1.0f,  1.0f,  1.0f }, {}, {1.0f, 0.0f}}, // 左上
			{{  1.0f, -1.0f,  1.0f }, {}, {0.0f, 1.0f}}, // 右下
			{{  1.0f,  1.0f,  1.0f }, {}, {0.0f, 0.0f}}, // 右上

			// 左
			{{ -1.0f, -1.0f, -1.0f }, {}, {1.0f, 1.0f}}, // 左下
			{{ -1.0f, -1.0f,  1.0f }, {}, {0.0f, 1.0f}}, // 左上
			{{ -1.0f,  1.0f, -1.0f }, {}, {1.0f, 0.0f}}, // 右下
			{{ -1.0f,  1.0f,  1.0f }, {}, {0.0f, 0.0f}}, // 右上

			// 右
			{{  1.0f, -1.0f, -1.0f }, {}, {0.0f, 1.0f}}, // 左下
			{{  1.0f, -1.0f,  1.0f }, {}, {1.0f, 1.0f}}, // 左上
			{{  1.0f,  1.0f, -1.0f }, {}, {0.0f, 0.0f}}, // 右下
			{{  1.0f,  1.0f,  1.0f }, {}, {1.0f, 0.0f}}, // 右上

			// 下
			{{ -1.0f, -1.0f,  1.0f }, {}, {0.0f, 0.0f}}, // 左下
			{{ -1.0f, -1.0f, -1.0f }, {}, {0.0f, 1.0f}}, // 左上
			{{  1.0f, -1.0f,  1.0f }, {}, {1.0f, 0.0f}}, // 右下
			{{  1.0f, -1.0f, -1.0f }, {}, {1.0f, 1.0f}}, // 右上

			// 上
			{{ -1.0f,  1.0f,  1.0f }, {}, {0.0f, 0.0f}}, // 左下
			{{ -1.0f,  1.0f, -1.0f }, {}, {0.0f, 1.0f}}, // 左上
			{{  1.0f,  1.0f,  1.0f }, {}, {1.0f, 0.0f}}, // 右下
			{{  1.0f,  1.0f, -1.0f }, {}, {1.0f, 1.0f}}, // 右上
		},
		{
			// 前
			0, 1, 2, // 三角形1つ目
			2, 1, 3, // 三角形2つ目

			// 後
			6, 7, 4, // 三角形1つ目
			4, 7, 5, // 三角形2つ目

			// 左
			8, 9, 10, // 三角形1つ目
			10, 9, 11, // 三角形2つ目

			// 右
			14, 15, 12, // 三角形1つ目
			12, 15, 13, // 三角形2つ目

			// 下
			16, 17, 18, // 三角形1つ目
			18, 17, 19, // 三角形2つ目

			//// 上
			22, 23, 20, // 三角形1つ目
			20, 23, 21, // 三角形2つ目
		}
		))
{
	vtIdx.Initialize(true);
}

void Model::Draw(Transform& trfm, MatViewProjection& vp, const UINT tex)
{
	trfm.Affine(vp.view.m, vp.pro.m);
	vtIdx.SetCommand();
	trfm.SetCommand();
	texManager->SetCommand(tex);
	vtIdx.Draw();
}

