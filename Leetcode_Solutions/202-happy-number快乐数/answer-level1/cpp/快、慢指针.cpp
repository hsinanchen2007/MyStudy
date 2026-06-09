### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了55.99%的用户

### 代码

```cpp
class Solution {
public:
	int isHappyCore(int n){
		int n_next = 0;
    	while(n){
    		n_next += pow(n%10,2);
    		n /= 10;
    	}
    	return n_next;
	}
    bool isHappy(int n) {
    	int slow = n;
    	int fast = n;
    	do{
    		slow = isHappyCore(slow);
    		fast = isHappyCore(fast);
    		fast = isHappyCore(fast);
    	}while(slow != fast);

    	return slow == 1;
    }
};
```