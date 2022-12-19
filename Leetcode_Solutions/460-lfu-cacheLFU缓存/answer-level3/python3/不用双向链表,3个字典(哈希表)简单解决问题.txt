### 解题思路
1. 三字典:dic字典存储键和值,value字典存储get或者put的次数,get_put字典存储这个key对应的是第几次get/put(用于反应相同value情况下,那个key更'新') -->
2. git函数返回dic中key对应vulue,将中key对应的value+1,并更新get_put中这个key对应的self.time值
3. put函数如果未满就向dic和中添加,如果满了就求出中self.value中最小的value,并在dic和value,get_put中去除key这一项

### 代码

```
class LFUCache:
    def __init__(self, capacity: int):
        self.dic={}
        self.value={}
        self.n=capacity
        self.time=0 #用于表示当前key是第几次访问get或者put操作
        self.get_put={} #用于存储key对应的time集合

    def get(self, key: int) -> int:
        self.time+=1
        if key in self.dic:
            self.value[key]+=1
            self.get_put[key]=self.time
            return self.dic[key]
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        self.time+=1
        if self.n==0:
            return -1
        if len(self.dic)<self.n:
            if key in self.value:
                self.dic[key]=value
                self.value[key]+=1
                self.get_put[key]=self.time
            else:
                self.dic[key]=value
                self.value[key]=1
                self.get_put[key]=self.time
        else: #如果添加的key就在dic中,则只需要更改key对应的value值,并使使用次数增加
            if key in self.value:
                self.dic[key] = value
                self.value[key]+=1
                self.get_put[key]=self.time
            else:
                mins=min(self.value.values())#sefl.value中可能有很多key的value值都是mins,接下来要寻找self.get_put中self.time最小的key
                min_dic={} #存储相同value情况下不同的self.time值
                for keys,item in self.value.items():
                    if item==mins:
                        min_dic[keys]=self.get_put[keys]
                keies=min(min_dic,key=lambda x:min_dic[x]) #这样求出来的keies就是相同value(get\put次数)情况下,更"旧"的key
                self.value.pop(keies)
                self.dic.pop(keies)
                self.get_put.pop(keies)

                self.dic[key] = value
                self.value[key]=1
                self.get_put[key] = self.time
```