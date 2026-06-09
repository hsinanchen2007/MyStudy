### 解题思路
![image.png](https://pic.leetcode-cn.com/bdd0cb785c42ea3d9d57a0f751402a00f45d55b4a9506dc186ccf46fc119d247-image.png)
利用flag标签记录是上山还是下山，然后遍历数组，分情况讨论，详细见注释。

### 代码

```cpp
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size() < 3)  //如果数组长度小于3，不含山脉
        return 0;
         int flag = 0;  //标记状态，0为平地，1为上山，-1为下山
         int right = 0, ans = 0, count = 0;
         while(right < A.size() - 1)
         {
             if(A[right] < A[right + 1])  
             {
                 if(flag == 0)  //平地时，修改状态为上山，count加1
                 {
                     count ++;
                     flag = 1;
                 }
                 else if(flag == 1)  //上山时，count加1
                 count ++;
                 else  //下山时，说明所在位置是山脉的最后一座山，以后状态为上山
                 {
                     count ++;
                     ans = max(ans, count);  //山脉结束，更新ans
                     count = 1;  //易错点：所在位置既是前一个山脉的结尾，也是下一个山脉的开头，故count为1
                     flag = 1;  //修改状态
                 }
                 right ++;  //指针右移
             }
             else if(A[right] > A[right + 1])
             {
                 if(flag == 1)  //上山时，说明开始下山
                 {
                     count ++;
                     flag = -1;  //修改状态
                 }
                 else if(flag == -1)  
                 count ++;
                 right ++;  //flag为0时没有额外操作，因为山脉不能直接下山
             }
             else
             {
                 if(flag == 1)  //上山时，山脉作废
                 {
                 count =0;
                 flag = 0;
                 }
                 else if(flag == -1)  //下山时，说明山脉结束
                 {
                     count ++;
                     ans =max(ans, count);  //更新ans
                     count = 0;  //因为是平地，故所在位置不属于下一个山脉
                     flag = 0;
                 }
                 right ++;
             }
         }
         if(flag == -1)  //易错点：如果数组遍历到了最后一位，并且还是下山，上面的代码没有覆盖到此种情况，故要更新ans,所处位置也属于山脉，故count加1
         return max(ans, count + 1);
         return ans;
    }
};
```