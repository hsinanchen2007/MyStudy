### 解题思路
耿直单纯的双指针思路
这次的想法也非常简单，我的设计是创建两个指针，一个是可复位指针（自动跳回初始位），一个是可循环指针（行进至字符串末尾自动跳回字符串首）
算法思路是这样的：
0.只处理长度相等的字符串，不等的情况直接返回False
1.复位指针指向s1的首元素
2.循环指针指向s2的首元素
3.如果两个指针指向元素相同，则一起后移一位，相同元素计数器+1
4.如果两个指针指向元素不同，循环指针后移一位，复位指针复位到字符串首位，相同元素计数器清零
5.如果相同元素计数器等于字符串长度则说明，双指针共通扫描过了一串完全相同的字符串，且串长度等于扫描串长度，便判定为两字符串为轮转串
6.如果循环指针轮转了2倍字符串长度依旧没有出现相同元素计数器与字符串长度想等的情况，则判明两字符串不为轮转串

附1：循环指针的实现使用的是余数思路，在我的设计里，point_s2_circle是一个不断加1的变量，判断已经循环过两次的参照也是这个变量，但是在控制字符串循环的时候，一旦point_s2_circle超过字符串长度后便会溢出，为了做到循环，我实际上用point_s2_circle对字符串长度s_length求余数的方法实现了指针到达字符串末尾后自动跳回字符串首位的操作，point_s2 = point_s2_circle%s_length就是为了实现这个想法写入的。
附2：在提交的时候被“”和“”的测试数据坑了（笑），于是简单粗暴的设计了if len(s1) == len(s2) == 0: return True的针对性操作。不知道有没有更好的办法可以把这个判断融入程序逻辑里，若各位大佬有所了解，请一定指点一二，万分感谢
### 代码

```python
class Solution(object):
    def isFlipedString(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1) != len(s2): return False
        if len(s1) == len(s2) == 0: return True
        point_s1 = 0
        point_s2 = 0
        point_s2_circle = 0
        s1_list = list(s1)
        s2_list = list(s2)
        s_length = len(s1)
        equal_counter = 0

        while point_s2_circle < s_length*2:
            if s1_list[point_s1] == s2_list[point_s2]:
                point_s1+=1
                equal_counter +=1
            else:
                point_s1 = 0
                equal_counter = 0
            point_s2_circle+=1
            point_s2 = point_s2_circle%s_length
            if equal_counter == s_length:
                return True
                break
        return False
```