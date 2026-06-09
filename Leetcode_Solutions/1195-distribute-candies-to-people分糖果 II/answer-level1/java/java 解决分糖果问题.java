### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] res=new int [num_people];
        //记录当前应该分的糖果数
        int cur=1;
        //记录分的次数
        int count =0;
        while(candies>0){
            //通过分的次数来计算得出对应数组下标
            int index=count%num_people;
            if(candies>=cur){
                candies-=cur;
                res[index]=res[index]+cur;
                count++;
                cur++;
            }else{
                //糖果分完，结束循环
                res[index]=res[index]+candies;
                break;
            }
        }
        return res;
    }
}
```