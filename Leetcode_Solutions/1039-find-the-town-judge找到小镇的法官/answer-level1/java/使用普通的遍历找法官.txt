### 解题思路
![123.jpg](https://pic.leetcode-cn.com/dd22ff71e60a4bf9fdee7842a750d07cd6f124cf802f57c8831ed09d343078d4-123.jpg)
此处撰写解题思路

### 代码

```java
class Solution {
    public int findJudge(int N, int[][] trust) {
        int trust_len;
        int i = 0, peopleLen = 0, num = 0, trustNum = 0;
        int people[] = new int[N];
        trust_len = trust.length;
        if(trust_len < N-1) {//如果trust长度太短就不存在
        	return -1;
        }
        for(i = 0;i<trust_len;i++) {//标记信任别人的人
        	people[trust[i][0]-1] = 1;
        }
        for(i = 0;i<N;i++) {//找出不信任任何人的人
        	if(people[i] == 0) {
        		num = i+1;
        		peopleLen++;
        	}
        }
        if(peopleLen != 1) {//不信任任何人的人不是一个，就不存在
        	return -1;
        }
        for(i = 0;i<trust_len;i++) {//看这个不信任任何人的人是不是被其他所有人信任
        	if(trust[i][1] == num) {
        		trustNum++;
        	}
        }
        if(trustNum == N-1) {//都满足条件就返回法官
        	return num;
        }
        return -1;//不满足就不存在
    }

}
```