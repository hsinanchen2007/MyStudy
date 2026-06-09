新手小白第一次做困难题，一把辛酸泪啊！！！没想到最后结果还蛮不错的，真是鸡冻的不行，写下来这第一次题解！！！
核心思路很简单，但是也想了好久呀，学习之路任重而道远啊！
双峰求解，意思就是先找到最高点，然后向左，向右分开递归找次高峰， 最高峰跟次高峰之间的洞洞就是能储存雨水的量，一直到两边找到起点跟终点。
代码是第一版，写的挺丑的，马上12点了，赶个末班车，就不改啦~~ 大佬们勿怪。

```
class Solution {
public:
    int Count = 0;

    int trap(vector<int>& height) {
    if(!height.size() || height.size()==1|| height.size() ==2) return Count; 
    auto biggest = std::max_element(std::begin(height), std::end(height));   //先找到最大的索引
    int max = std::distance(std::begin(height), biggest);
    _find(max, true, height);   //从最大值的左边开始遍历
    _find(max, false, height);  //从右边
    return Count;
    }

    void _find(int max, bool flag, vector<int>& height){
        if(flag){
            if(max == 0){    //递归结束
                return;
            }
            // auto biggest = std::max_element(height.begin()+max-1, height.begin()); 出错了-- 不能这么用
            //int max_1 = std::distance(std::begin(height), biggest);
            int temp = height[max-1];
            int max_1 = max-1;
            for(int i = max-1;i>-1;i--){    //找到最大值
                if(height[i] > temp){
                    temp = height[i];
                    max_1=i;
                }
            }
            for(int i = max_1+1;i<max;i++){    //最大值之间 的空隙
                Count += height[max_1] - height[i];
            }
            _find(max_1, flag, height);
        }
        else{
            if(max == height.size()-1){
                return;
            }
            auto biggest = std::max_element(height.begin()+max+1, height.end());
            int max_1 = std::distance(std::begin(height), biggest);
            for(int i = max_1-1;i>max;i--){
                Count += height[max_1] - height[i];
            }
            _find(max_1, flag, height);
        }
    }
};
```
