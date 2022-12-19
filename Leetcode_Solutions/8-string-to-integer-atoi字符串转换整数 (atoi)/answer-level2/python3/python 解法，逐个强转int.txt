
多提交几遍刷出了24ms，虽然好像没什么意义orz，但是开心！
![image.png](https://pic.leetcode-cn.com/0e3ac41fbf0636375e2dd469a361f0abec2312736a3a46c7128d4e6e9d22ecdb-image.png)
方法是利用python直接强制转换
```
class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        #去掉左边字符
        str=str.lstrip()
        #如果字符串空，返回
        if len(str)==0:
            return 0
        #设置默认输出为0
        last=0
        #如果有符号设置起始位置2，其余的为1
        i=2 if str[0]=='-'or str[0]=='+'  else 1
        #循环，直到无法强转成int，跳出循环
        while i <= len(str):
            try:
                last=int(str[:i])
                i+=1
            except:
                break
        #如果数字超出范围，返回范围最大值
        if last<-2147483648 :
            return -2147483648
        if last>2147483647:
            return 2147483647
        return last
        
```
