水平一般，能力有限，官方题解给出的几种方法我一种也没想到，就自己琢磨了个菜鸡解法。
通过题中用例可观察得知接完雨水后必定成为一个类似山峰的形状，该形状不存在凹下去的部分，那么就可以先寻找这个形状的最大值，最大值将这个图形分为不严格递增和不严格递减两块区域，对这两块区域填上凹下去的部分就行了
```
class Solution {
public:
    int trap(vector<int>& height) {
        int max = 0, pos = 0, sum = 0, temp = 0;
        for(int i = 0; i < height.size(); i++){
            if(height[i] > max){
                max = height[i];
                pos = i;
            }
        }
        for(int i = 0; i < pos; i++){
            if(height[i] > temp){
                temp = height[i];
            }else{
                sum += (temp - height[i]);
            }
        }
        temp = 0;
        for(int i = height.size() - 1; i > pos; i--){
            if(height[i] > temp){
                temp = height[i];
            }else{
                sum += (temp - height[i]);
            }
        }
        return sum;
    }
};
```
