### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        if(candies==0)
            return new int[num_people];
        int [] res = new int[num_people];
        int j=1;
        while(candies>=j*(j+1)/2)
        {
            j++;
        }
        int rom = candies - j*(j-1)/2;//最后一个位置的个数
        int ceng = (j-1)/num_people;   //填满的层数
        int po  = j % num_people; //最后一个的位置
        if(po==0)
            po = num_people;
        if(ceng==0)
        {
            for(int i=0;i<po;i++)
            {
                res[i] = i+1;
                if(i==po-1)
                    res[i]=rom;
            }
        }
        else
        {
            for(int i=0;i<num_people;i++)
            {
                res[i] = (i+1)*ceng+ceng*(ceng-1)/2*num_people;
            }
            for(int i=0;i<po;i++)
            {
                res[i] = (i+1)*(ceng+1)+ceng*(ceng+1)/2*num_people;
                if(i==po-1)
                    res[i]=(i+1)*ceng+ceng*(ceng-1)/2*num_people+rom;
            }
        }
        return res;
    }
}



// class Solution {
//     public int[] distributeCandies(int candies, int num_people) {
//         int[] ans = new int[num_people];
//         int i = 0;
//         while (candies != 0) {
//             ans[i % num_people] += Math.min(candies, i + 1);
//             candies -= Math.min(candies, i + 1);
//             i += 1;
//         }
//         return ans;
//     }
// }
```