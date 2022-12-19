### 解题思路
    两个for循环嵌套：
        第一个for循环拿出数组中的元素；
        第二个for循环统计元素个数，元素个数过半，即为多数元素；

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int answer = 0;             //定义要返回的多数元素
       
        for(int i : nums) {         //遍历数组，拿出数组中的元素
            answer = i;             //假定次元素就是多数元素
            int counter = 0;        //定义计数器，每次更换元素，计数器会归零
            for(int j : nums) {     //再次遍历数组，统计此元素个数
                if(answer == j) {
                    counter++;
                    if(counter > nums.length / 2) { //如果此元素过半，即为多数元素
                        return answer;
                    }
                }
            }
        }
        return -1;                   //没有多数元素，结果返回-1；
    }
}
```