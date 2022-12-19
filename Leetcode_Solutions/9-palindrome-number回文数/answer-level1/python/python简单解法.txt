a=input('请输入数字：')
a=list(a)
b=reversed(a)
b=list(b)
if a==b:
    print('是回文数')
else:
    print('不是回文数')
用reversed函数将字符串顺序倒置