### 解题思路
我们可以使用一个二维数组（ratings.length X 2）来存储孩子们之间的关系，代码中我用变量rel表示。
对于每一个孩子i, rel[i]是一个只包含两个元素的数组，
- 如果这个孩子左边的孩子比他高，那么rel[i][0]存储的数为i-1，代表着这个孩子的糖果数将比左边孩子获得的糖果数多。
- 如果这个孩子右边的孩子比他高，那么rel[i][1]存储的数为i+1，代表着这个孩子的糖果数将比右边孩子获得的糖果数多。

接下来使用一个递归函数get(i)获得第i个孩子的可以获得的糖果数。具体来说，如果
1.rel[i]的两个元素都不为默认值的话（在我的代码中默认值是-1）那么他既比左边的孩子高，也比右边的孩子高，糖果数为邻居孩子的糖果数的最大值多1, 也就是递归的调用自己：max(get(i-1), get(i+1))+1.
2.只有rel[i][0]不为默认值，比左边孩子高，那么糖果数为get(i-1)+1
3.只有rel[i][1]不为默认值，比右边孩子高，那么糖果数为get(i+1)+1
4.rel[i]的两个元素都为默认值的话，那么他既没有左边的孩子高，也没有右边的孩子高，糖果数为1.

同时在调用递归函数的时候用一个数组candies存储每个孩子的糖果数，防止不必要的重复递归（记忆化）

### 代码

```java
class Solution {
    int[][] rel;
    int[] candies;


    public int candy(int[] ratings) {
        if(ratings.length <= 1){
            return ratings.length;
        }
        if(ratings.length==2){
            if(ratings[0]==ratings[1]){
                return 2;
            }else{
                return 3;
            }
        }
        candies = new int[ratings.length];
        rel = new int[ratings.length][];
        for(int i=1;i<ratings.length-1;i++){
            int[] temp = {-1, -1};
            if(ratings[i] > ratings[i-1]){
                temp[0] = i - 1;
            }
            if(ratings[i] > ratings[i+1]){
                temp[1] = i + 1;
            }
            rel[i] = temp;
        }
        int[] first = {-1, -1};
        int[] last = {-1, -1};
        if(ratings[0]> ratings[1]){
            first[1] = 1;
        }
        if(ratings[ratings.length-1]> ratings[ratings.length-2]){
            last[0] = ratings.length - 2;
        }
        rel[0] = first;
        rel[ratings.length-1] = last;
        int res = 0;
        for(int i=0;i<ratings.length;i++){
            res += get(i);
        }
        return res;
    }

    private int get(int i){
        if(candies[i]!=0){
            return candies[i];
        }
        if(rel[i][0]==-1 && rel[i][1]==-1){
            candies[i] = 1;
        }else if(rel[i][0]!=-1 && rel[i][1] != -1){
            candies[i] = Math.max(get(rel[i][0]), get(rel[i][1]))+1;
        }else if(rel[i][0]!=-1){
            candies[i] = get(rel[i][0])+1;
        }else{
            candies[i] = get(rel[i][1])+1;
        }
        return candies[i];
    }
}
```