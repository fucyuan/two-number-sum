#include <iostream>
#include <vector>
#include <unordered_map>
/*unordered_map��C++��׼���е�һ���������������ṩ��һ�ֽ�����ֵ���������ķ�ʽ��
unordered_map�ǻ��ڹ�ϣ��ʵ�ֵģ���˾��п��ٵĲ��ҺͲ�����������ԡ�

unordered_map�е�ÿ��Ԫ�ض���һ����ֵ�ԣ����м���Ψһ�ģ���ֵ�����ظ���
���������ֵ��ӳ������ݽṹ��ͨ���������Ҷ�Ӧ��ֵ��

ʹ��unordered_map������ƽ������ʱ�临�Ӷȣ�O(1)����ִ�в��롢ɾ���Ͳ��Ҳ�����
��ʹ�����ǳ��ʺ���Ҫ��Ч���ҺͲ���ĳ�����

������unordered_map��һЩ����������

insert(key, value)����unordered_map�в���һ����ֵ�ԡ�
erase(key)����unordered_map��ɾ��ָ������Ԫ�ء�
find(key)������ָ������Ӧ��ֵ��������һ��������ָ���λ�á�
count(key)������ָ������unordered_map�г��ֵĴ�����0��1����
size()������unordered_map��Ԫ�صĸ�����
��ʾ�������У�����ʹ��unordered_map<int, int>���洢���ֺ����ǵ���������������ͨ��������Ϊ�����ٲ��Ҷ�Ӧ���������Ա����ҵ�Ŀ��ֵʱ���ؽ����*/
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
