将数组自身元素从尾到头push_back一遍，再把原来的元素删除。效率低内存占用小好理解。
可能需要注意的点：
1. 最后一个元素不用移动
2. end()的用法

    class Solution {
    public:
        void reverseString(vector<char>& s) {
            int orisize=s.size();
            for(int i=orisize-2;i>=0;i--){
                s.push_back(s[i]);
                s.erase(s.end()-(orisize-i)-1); //s.end()返回的是s向量中最后一个元素的下一个位置
            }
        }
    };
