计算机专业大二的学生。很惭愧，看清题之后去研究了很久vector是啥，很难过在此之前只会用最简单的粗暴的方式初始化数组然后两个循环加求和比较。第一次在这里做题，感觉开阔了视野，至少我知道了vector，并且能初级的运用它。
虽然代码成功提交了，可是用时很长。最近也在学习算法设计的课程，希望未来能在这里能有更多的收获。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> A;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((nums[i]+nums[j]==target)&&(i!=j)){
                    A.push_back(i);
                    A.push_back(j);
                }
            }
        }
        return A;
    }
};
这是我的代码，之后我会回来再做的。希望那时我可以有所长进。