双向指针，头尾各一个，两数之和与目标值比较决定指针的移动；
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indices;
        int size = numbers.size();
        int i = 0;
        int j = size-1;
        while(i >= 0 && j < size)
        {
            if(numbers[i] + numbers[j] > target)
           {
               j--;
               continue;
           }
           if(numbers[i] + numbers[j] < target)
           {
               i++;
               continue;
           }
           if(numbers[i] + numbers[j] == target)
           {
               indices.push_back(i+1);
               indices.push_back(j+1);
               break;
           }
        }
        return indices;
    }
};