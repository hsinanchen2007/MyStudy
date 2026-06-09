python3的两种解法

法1：根据组合数公式n!/(i!*(n-i)!)计算
```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        # 法1：根据组合数公式n!/(i!*(n-i)!)计算
        if rowIndex < 0:
            return []
        factorials = [1]*(rowIndex+1) 
        ans = [1]*(rowIndex+1)
        for i in range(1, rowIndex+1):
            factorials[i] = factorials[i-1]*i # 0!~rowIndex!
        # print(factorials)
        for i in range(rowIndex): # 根据组合数公式计算n!/(i!*(n-i)!)
            ans[i] = factorials[-1]//(factorials[i]*factorials[rowIndex-i])
        return ans
```
法2：根据组合数公式C(n,i)=n!/(i!*(n-i)!)直接由C(n,i)算C(n,i+1),后者是前者的(n-i)/(i+1)倍
```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        # 法2：根据组合数公式C(n,i)=n!/(i!*(n-i)!)直接由C(n,i)算C(n,i+1),后者是前者的(n-i)/(i+1)倍
        if rowIndex < 0:
            return []
        ans = [1]*(rowIndex+1)
        for i in range(rowIndex):
            ans[i+1] = ans[i]*(rowIndex-i)//(i+1)
        return ans
```
python3解法2的C++版
```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if(rowIndex<0)
            return res;
        res.push_back(1);
        for(int i=0; i<rowIndex; ++i)
            res.push_back(static_cast<int>(double(res[i])*(rowIndex-i)/(i+1))); //注意res[i]不进行类型转换会造成结果overflow
        return res;
    }
};
```