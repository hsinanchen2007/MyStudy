### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] array=new int[num_people];
        int rest = candies;
        int last = 1;
        int index = 0;
        while (rest>0){
            array[index%num_people]+=last;
            rest-=last;
            last++;
            index++;
            if(last>=rest){
                array[index%num_people]+=rest;
                break;
            }
        }
        return array;
    }
}
```