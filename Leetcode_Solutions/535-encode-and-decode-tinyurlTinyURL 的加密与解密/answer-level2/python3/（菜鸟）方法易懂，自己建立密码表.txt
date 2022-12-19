```
#思路，自己建立密码对应表 将26个乱序的大写字母与26个小写字母一一对应，根据index不变进行替换 
#大写换小写，小写换大写，但是大小写字母不对应，如M对应q  根据index进行编码解码
#因为字符串不可动，先转为list，变动完再转为字符串
dx = 'MNBVCXZLKJHGFDSAPOIUYTREWQ'
xx = 'qwertyuiopasdfghjklzxcvbnm'#26个字母  上下对应index的字母进行替换，编码解码，按照index进行
#编码将大写全换为小写，小写换为大写；解码将大写换为小写，小写换为大写
class Codec:
    
    def encode(self, longUrl: str) -> str:
        
        longUrl = list(longUrl)   #变成list好进行索引操作
        n = len(longUrl)
        for i in range(n):
            if longUrl[i] in dx:
                m = dx.index(longUrl[i])  #对应的索引
                longUrl[i] = xx[m]  #将大写换大写
            elif longUrl[i] in xx:     #小写换大写
                m= xx.index(longUrl[i])
                longUrl[i] = dx[m]

        longUrl = [str(j) for j in longUrl]   #元素变为str
        longUrl=''.join(longUrl)   #将list中元素取出组成字符串
        return longUrl

    def decode(self, shortUrl: str) -> str:
        shortUrl = list(shortUrl)
        n = len(shortUrl)
        for i in range(n):
            if shortUrl[i] in dx:
                m = dx.index(shortUrl[i])
                shortUrl[i] = xx[m]  #将大写换小写
            elif shortUrl[i] in xx:    #小写换大写
                m = xx.index(shortUrl[i])
                shortUrl[i] = dx[m]
        shortUrl = [str(j) for j in shortUrl]
        shortUrl=''.join(shortUrl)
        return shortUrl

```
