#pragma once

#include <memory>
#include <string>
#include <vector>

namespace Vulkan
{
	class Buffer;
	class CommandPool;
	class DeviceMemory;
	class Image;
}

namespace Assets
{
	class Model;

	class Scene final
	{
	public:

		Scene(const Scene&) = delete;
		Scene(Scene&&) = delete;
		Scene& operator = (const Scene&) = delete;
		Scene& operator = (Scene&&) = delete;

		Scene(Vulkan::CommandPool& commandPool, std::vector<Model>&& models, bool usedForRayTracing);
		~Scene();

		const std::vector<Model>& Models() const { return models_; }
		bool HasProcedurals() const { return static_cast<bool>(proceduralBuffer_); }

		const Vulkan::Buffer& VertexBuffer() const { return *vertexBuffer_; }
		const Vulkan::Buffer& IndexBuffer() const { return *indexBuffer_; }
		const Vulkan::Buffer& MaterialBuffer() const { return *materialBuffer_; }
		const Vulkan::Buffer& OffsetsBuffer() const { return *offsetBuffer_; }
		const Vulkan::Buffer& AabbBuffer() const { return *aabbBuffer_; }
		const Vulkan::Buffer& ProceduralBuffer() const { return *proceduralBuffer_; }
		//const TextureImage& TextureImage() const { return *textureImage_; }

	private:

		const std::vector<Model> models_;

		std::unique_ptr<Vulkan::Buffer> vertexBuffer_;
		std::unique_ptr<Vulkan::DeviceMemory> vertexBufferMemory_;

		std::unique_ptr<Vulkan::Buffer> indexBuffer_;
		std::unique_ptr<Vulkan::DeviceMemory> indexBufferMemory_;

		std::unique_ptr<Vulkan::Buffer> materialBuffer_;
		std::unique_ptr<Vulkan::DeviceMemory> materialBufferMemory_;

		std::unique_ptr<Vulkan::Buffer> offsetBuffer_;
		std::unique_ptr<Vulkan::DeviceMemory> offsetBufferMemory_;

		std::unique_ptr<Vulkan::Buffer> aabbBuffer_;
		std::unique_ptr<Vulkan::DeviceMemory> aabbBufferMemory_;

		std::unique_ptr<Vulkan::Buffer> proceduralBuffer_;
		std::unique_ptr<Vulkan::DeviceMemory> proceduralBufferMemory_;

		//std::unique_ptr<::TextureImage> textureImage_;
	};

}