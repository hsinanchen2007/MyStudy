### 解题思路
原谅我只会for循环=。=这应该是许多个差为一的等差数列，所以可以做两个循环，外循环是分糖果的轮次，内循环是每轮分糖果时遍历每个孩子，我们只要在每次循环中让孩子得到的糖果等于总糖果失去的糖果，并且在中间加一个判断，看看剩余糖果是否够给下一个孩子，不够的话就全部给下一个孩子，然后返回数组即可。

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] kids=new int[num_people];
        int sugar=candies;
        for(int i=0;sugar>0;i++){
            for(int j=0;j<num_people;j++){
                if(sugar>((i*num_people)+j)){
                    kids[j]=kids[j]+((i*num_people)+j+1);
                    sugar=sugar-((i*num_people)+j+1);
                }else{
                    kids[j]=kids[j]+sugar;
                    return kids;
                }
            }     
        }
        return kids;
    }
}

```