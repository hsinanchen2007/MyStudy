### 解题思路
参考了题解的java实现，写了c++发现执行效率特别低，而java效果还很好。
尝试把三目表达式变为if语句，没有影响。不确定是否是to_string耗时间

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int x = 0;
        string res = "";
        for(int i=a.size()-1,j=b.size()-1;(i>=0)||(j>=0);i--,j--){
            int sum = x;
            sum = sum + (i>=0 ? a[i]-'0':0);
            sum = sum + (j>=0 ? b[j]-'0':0);
            x = sum/2;
            res = to_string(sum%2) + res;
        }
        if(x>0){
            res = to_string(x) + res;
        }
        return res;
    }
};
```
java实现
```java
class Solution {
    public String addBinary(String a, String b) {
    	StringBuilder ans = new StringBuilder();
    	int x = 0;
    	for(int i=a.length()-1, j=b.length()-1;i>=0||j>=0;i--,j--) {
    		int sum = x;
    		sum += i>=0 ? a.charAt(i) - '0' :0;
    		sum += j>=0 ? b.charAt(j) - '0' :0;
    		ans.append(sum%2);
    		x = sum / 2;
    	}
    	ans.append(x==1 ? x: "");
    	return ans.reverse().toString();
    }
}

```