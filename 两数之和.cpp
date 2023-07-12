#include <iostream>
#include <vector>
#include <unordered_map>
/*unordered_map是C++标准库中的一个关联容器，它提供了一种将键和值关联起来的方式。
unordered_map是基于哈希表实现的，因此具有快速的查找和插入操作的特性。

unordered_map中的每个元素都是一个键值对，其中键是唯一的，而值可以重复。
它类似于字典或映射的数据结构，通过键来查找对应的值。

使用unordered_map可以在平均常数时间复杂度（O(1)）下执行插入、删除和查找操作，
这使得它非常适合需要高效查找和插入的场景。

以下是unordered_map的一些常见操作：

insert(key, value)：向unordered_map中插入一个键值对。
erase(key)：从unordered_map中删除指定键的元素。
find(key)：查找指定键对应的值，并返回一个迭代器指向该位置。
count(key)：返回指定键在unordered_map中出现的次数（0或1）。
size()：返回unordered_map中元素的个数。
在示例代码中，我们使用unordered_map<int, int>来存储数字和它们的索引。这样可以通过数字作为键快速查找对应的索引，以便在找到目标值时返回结果。*/
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); i++) 
        {
            int complement = target - nums[i];

            if (numMap.find(complement) != numMap.end()) 
            {
                return { numMap[complement], i };
            }

            numMap[nums[i]] = i;
        }

        return {};
    }
};
std::vector<int> twoSum(std::vector<int>& nums, int target) 
{
    std::unordered_map<int, int> numMap;
    std::vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (numMap.find(complement) != numMap.end()) 
        {
            result.push_back(numMap[complement]);
            result.push_back(i);
            return result;
        }

        numMap[nums[i]] = i;
    }

    return result;
}

int main()
{
    std::vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
        std::cout << "Values: " << nums[result[0]] << ", " << nums[result[1]] << std::endl;
    }
    else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}
