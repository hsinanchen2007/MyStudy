![image.png](https://pic.leetcode-cn.com/468b8abd74726abd6f576c488560e840c0fe7a84e52c153f2d0300fab36f1d07-image.png)

### 解题思路
公式如下 
![image.png](https://pic.leetcode-cn.com/dbc6bd82c94428fdabd15c65b5258d956fcee0d880b32c5db33edab759cf22cb-image.png)

```
int count(int n){
    int s=1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int a=0;
            while(n%i==0){
                n/=i;
                a++;
            }
            s=s*(a+1);
        }
    }
    if(n>1) s=s*2;
    return s;
}
```
```
int sum(int n){
    int s=1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int a=1;
            while(n%i==0){
                n/=i;
                a*=i;
            }
            s=s*(a*i-1)/(i-1);
        }
    }
    if(n>1) s=s*(1+n);
    return s;
}
```
把两个合并。

如果因子数>4的时候 就退出不再继续计算。
### 代码

```cpp

using namespace std;
class Solution {
	//因子数
	int sumAndCnt(int n) {
		int s = 1;
		int scnt = 1;
		for (int i = 2;i*i <= n;i++) {
			if (n%i == 0) { //n已经把前边的质数都除尽了，所以相当于后边的非质数已经不可能余数为0了。
				int a = 1;
				int cnt = 0;
				while (n%i == 0) {
					n /= i;
					a *= i;
					cnt++;
				}
				scnt = scnt*(cnt + 1);
				if (scnt > 2 && n >1) {  //因为最后还有*2 所有这里>2的时候 因子数就会大于4
					break;
				}
				s = s*(a*i - 1) / (i - 1); // 一个公式  记住就行
			}

		}
		if (n>1) scnt = scnt * 2;
		if (n>1) s = s*(1 + n);
		if (scnt != 4)
		{
			return 0;
		}
		return s;
	}

public:
    int sumFourDivisors(vector<int> &nums)
    {
		if (nums.size() == 0){
			return 0;
		}
		int allsum = 0;
		for (int i : nums) {
				allsum += sumAndCnt(i);
		}

		return allsum;
    }
};
```