### 解题思路
首先计算出完整的分发了多少轮，然后进行第一轮赋值，然后算出剩下的糖果数量，分发一轮

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] people = new int[num_people];
        int count = 0; //完整的有多少轮

        int n = num_people;

        while( n * (n + 1) / 2 <= candies) {
            //System.out.println(n);
            count ++;
            n += num_people;
        }

        for (int i = 0; i < num_people; i++) {
            people[i] = count * (i + 1) + (count - 1) * count / 2 * num_people;
        }
        
        int div = candies - (num_people * count + 1) * (num_people * count) / 2;
        

        int much = num_people*count+1;
        for (int i = 0; i < num_people; i++) {
            if (div > 0) {
                if (div >= much) {
                    people[i] += much;
                    div -= much;
                    much++;
                } else {
                    people[i] += div;
                    div = 0;
                }
            } else {
                break;
            }
        }
        
        return people;
    }
}
```