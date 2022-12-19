方法一 
eg 123456
旋转后分以下情况：
1. 123456 不出现num[i-1]>num[i]情况
2. 345612 若出现num[i-1]>num[i]则可找到最小值为num[i]
3. 654321 连续出现多次num[i-1]>num[i]情况
故需要一个标志位flag
对于情况1，flag=0;
对于情况2，flag=1;
对于情况3，flag=2; 只要出现两次num[i-1]>num[i]，就可确定是情况3，结束遍历
```
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int size=numbers.size(),i=1,tp=0,flag=0;
        for(;i<size;i++){
            if(numbers[i-1]<numbers[i] && flag) break; //情况2
            if(numbers[i-1]>numbers[i] && flag){
                flag++;
                break; //情况3
            } 
            if(numbers[i-1]>numbers[i] && !flag){
                tp=i;
                flag++;
            }
        }
        if(flag==1) return numbers[tp];
        if(flag==2) numbers[size-1];
        return numbers[0];
    }
};
```
方法二 二分法

中间值mid与右边界right比较还是与左边界left比较？

若与左边界比较：
1. 123456 num[mid]=num[2]=3<num[left]=6 最小值在mid左边
2. 345612 num[mid]=num[2]=5>num[left]=2 最小值在mid右边
3. 654321 num[mid]=num[2]=4>num[left]=1 最小值在mid右边
从上面可以看到当num[mid]>num[left]时并不能判断最小值在mid哪一边

若与右边界比较：
1. 123456 num[mid]=num[2]=3<num[right]=1 最小值在mid左边
2. 345612 num[mid]=num[2]=5>num[right]=3 最小值在mid右边
3. 654321 num[mid]=num[2]=4>num[right]=6 最小值在mid右边
不存在上面问题，但num[mid]=num[right]时并不能确定最小值在mid哪一边，比如1,0,1,1,1旋转点在右排序数组中，比如1,1,1,0,1旋转点在左排序数组中。此时缩小搜索范围。

```
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int i=0,j=numbers.size()-1;
        while(i < j){
            int m = (i + j) / 2;
            if(numbers[m] > numbers[j]) i = m + 1;
            else if(numbers[m] < numbers[j]) j = m;
            else j -= 1;
        }
        return numbers[i];
    }
};
```

