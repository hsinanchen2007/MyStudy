### 解题思路
1. 将字符串首先按照空格分割， 每一项存入列表中
2. 解决列表中存在空格的问题，涉及到几种去掉空格的方法
```python
#（1）for循环遍历数组中每个元素，输出
for i in ss :
    if i == '' : ss.remove(i)
#无效，无法去掉末尾的空格
```

```python
#（2）while循环来实现
while '' in ss :
    ss.remove('')
#亲测有效
```

```python
#（3）更加简洁的写法
ss = [x for x in ss if x != '']
#亲测有效
```
```python
#（4）先得到列表中空格的个数，然后依次去除
for i in range(ss.count('')):
    ss.remove('')
#亲测有效
```

3. 再将列表反转，以空格为分割符，拼接成一个字符串
4. 返回该字符串


### 代码

```python
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s == None : return ""
        ss = s.split(" ")
        ss = [x for x in ss if x != '']
        sss = " ".join(ss[::-1])
        return sss
```