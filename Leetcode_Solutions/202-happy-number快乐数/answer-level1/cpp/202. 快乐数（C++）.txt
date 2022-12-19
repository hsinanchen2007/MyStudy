# 202. 快乐数
```
class Solution {
private:
	set<int> m_set;	//用于保存已经出现过数的集合
public:
    bool isHappy(int n) {
		//如果当前判断的数树已经出现过，则为死循环返回false
		if(m_set.find(n) != m_set.end()){
			return false;
		}else{
			m_set.insert(n);	//将当前判断的数为被查询过，则加入集合
		}
		
		//如果当前判断的数1，则为快乐数返回true
		if(n == 1){
			return true;
		}
		
		//不是快乐数，计算出下一个数
		int dst = 0;
		do{
			dst += (n%10)*(n%10);
		}while((n /= 10) != 0);
		
		//递归判断下一个数是否为快乐数，并将其结果作为返回值
		return isHappy(dst);
    }
};
```
