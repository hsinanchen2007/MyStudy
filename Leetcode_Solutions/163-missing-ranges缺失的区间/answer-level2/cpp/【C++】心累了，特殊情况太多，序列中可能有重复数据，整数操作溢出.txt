1.小心整数操作溢出
2.区间中数据可能有重复
3.区间的门限可能不合理
4.如果返回vector<string> output 这种类型，异常就给容器器中push一个空串
5.处理第一个和最后一个节点
```
/*
* Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
* Description: missing-ranges
* Author: Nicolas
* Create: 2019.9.19
*/
//Line 70: Char 27: runtime error: signed integer overflow: -2147483648 - 1 cannot be represented in type 'int' (solution.cpp)

class Solution
{
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
    {
        if (lower > upper) {
            output.push_back("");
            return output;
        }

        if (nums.size() == 0 ) {
            stringstream ss;
            if (lower == upper) {
                ss << lower;
            } else {
                ss << lower << "->" << upper;
            }
            output.push_back(ss.str());
            return output;
        }

        int start = lower;
        for (int i = 0; i < nums.size(); ++i) {
            if (isFirstNum(i)) {
                if ((nums.at(i) > start)) {
                    pushLower(nums, i, lower);
                }
                start = nums.at(i);
                continue;
            }

            if (isContinue(nums, i, start)) {
                start = nums.at(i);
                continue;
            }
            pushRange(nums, i, start);
            start = nums.at(i);
        }

        int lastOneIndex = nums.size() - 1;
        if (isLastNum(lastOneIndex, nums)) {
            if (nums.at(lastOneIndex) < upper) {
                pushUpper(nums, lastOneIndex, upper);
            }
        }
        return output;
    }

    void pushRange(vector<int> &nums, int i, int start)
    {
        stringstream ss;
        if (isSingle(nums, i, start)) {
            ss << incInt(start);
        } else {
            ss << incInt(start) << "->" << decInt(nums.at(i));
        }
        output.push_back(ss.str());
    }

    int incInt(int start)
    {
        if (start == 0x7FFFFFFF) {
            return start;
        }
        return start + 1;
    }

    int decInt(int end)
    {
        if (end == 0x80000000) {
            return end;
        }
        return end - 1;
    }

    bool isSingle(vector<int> &nums, int i, int start)
    {
        return decInt(nums.at(i)) == incInt(start);
    }

    bool isContinue(vector<int> &nums, int i, int start)
    {
        return decInt(nums.at(i)) == start || nums.at(i) == start;
    }

    bool isFirstNum(int i)
    {
        return i == 0;
    }

    bool isLastNum(int i, vector<int> &nums)
    {
        return i == (nums.size() - 1);
    }

    void pushUpper(vector<int> &nums, int i, int upper)
    {
        stringstream ss;
        if (incInt(nums.at(i)) == upper) {
            ss << upper;
        } else {
            ss << incInt(nums.at(i)) << "->" << upper;
        }
        output.push_back(ss.str());
    }

    void pushLower(vector<int> &nums, int i, int lower)
    {
        stringstream ss;
        if (decInt(nums.at(i)) == lower) {
            ss << lower;
        } else {
            ss << lower << "->" << decInt(nums.at(i));
        }
        output.push_back(ss.str());
    }

private:
    vector<string> output;
};
```
