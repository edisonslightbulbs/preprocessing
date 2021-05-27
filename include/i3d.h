#ifndef INTACT_UTILS_H
#define INTACT_UTILS_H

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <thread>
#include <torch/script.h>

#include "intact.h"
#include "io.h"

namespace i3d {

void configTorch(
    std::vector<std::string>& classNames, torch::jit::script::Module& module);

void adapt(const int& index, Point& point,
    const std::vector<int16_t>& pCloudFrame,
    const std::vector<uint8_t>& imgFrame);

bool invalid(const int& index, const k4a_float2_t* ptr_xyTable,
    const uint16_t* ptr_depth);

bool invalid(const int& index, const int16_t* ptr_pCloudData,
    const uint8_t* ptr_imgData);

bool null(const int& index, std::vector<int16_t>& pCloudFrame,
    std::vector<uint8_t>& imgFrame);

void addXYZ(const int& index, std::vector<int16_t>& pCloudFrame);

void addXYZ(const int& index, std::vector<int16_t>& pCloudFrame,
    const int16_t* ptr_pCloudData);

void addPixel_GL(const int& index, std::vector<uint8_t>& imgFrame_GL);

void addPixel_GL(const int& index, std::vector<uint8_t>& imgFrame_GL,
    const uint8_t* ptr_imgData);

void addPixel_CV(const int& index, std::vector<uint8_t>& imgFrame_CV,
    const uint8_t* ptr_imgData);

void addPixel_CV(const int& index, std::vector<uint8_t>& imgFrame_CV);

bool inSegment(const int& index, const std::vector<int16_t>& pCloudFrame,
    const Point& minPoint, const Point& maxPoint);

void stitch(const int& index, Point& point, int16_t* ptr_pcl,
    uint8_t* ptr_img_GL, uint8_t* ptr_img_CV);

std::pair<Point, Point> queryBoundary(std::vector<Point>& points);
}
#endif /*INTACT_UTILS_H*/
