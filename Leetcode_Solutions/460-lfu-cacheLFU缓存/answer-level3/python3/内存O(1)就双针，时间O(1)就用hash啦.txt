小c醒了，发现自己身处一个昏暗的地下室，四周没有窗户。

“这里是哪里！？”

小c惊慌的站起来，身后突然亮起一道光。
小c回头看，是一台老旧的电视，电视上一个带着面具的脸。

“I want to play a game.”

那是带着变声器处理后的声音，小c慌乱的看着电视。
“你的身上绑了炸弹。时间到了就会爆炸。”

“你想让我做什么！为什么要绑架我！？”

“呵呵呵，如果你想活着出去...”
小c咽了咽口水，紧张地听着。

“就**实现一个LFU缓存的数据结构，而且get和put都必须在O(1)的复杂度**。”

“呃！多么恶毒啊。”

“线索已经摆在了房间里，想活命的话就好好利用起来吧。”

小c环顾地下室。
在昏暗的灯光下，他发现一具躺在地上的——hashmap。

小c心中大喜，他师兄说过
“**O(1)的数据结构问题？那必须用hashmap啊**！”

小c冲上去，对着hashmap说
“hashmap，帮帮我，我需要你来做O(1)的存取”

但hashmap只是虚弱的摇了摇头
“不行，光有我是不够的，我没法处理数序的问题。”
说完hashmap晕了过去。

“hashmap！！！”

“不行了，必须找别的方法来帮助hashmap。”

小c继续环顾四周。
“那是！排序！”

小c冲到排序身边，但发现排序已经口吐白沫，不省人事了。
“不行了，最快的排序都是O(n)的，即使时插入时排序，也是O(logN)的，完全无法匹敌”

“难道就没有插入和取出都是O(1)的，包含顺序的数据结构了吗！？”
小c趴在地上痛哭。

一个瘦长的身影走了过来，拍了拍小c的肩膀。
“你怎么能把我忘了呢？”

“你是！链表！”

“虽然我看上去最低端，数据结构课上都是放在第二章的新手入门级，但真实用起来，那我还是顶的啊。”

“链表插入和删除时O(1)，但链表的搜索是O(n)的啊！”

“你忘了那个老哥么。”
链表指了指躺在地上的hashmap。

“原来如此！**用hashmap做搜索，同时用链表维持使用频次的顺序**！”

“ **因为LFU的频次只更新会加1，对链表而言，就是修改相邻节点。** 这是只有在+1时，才能用到的方法啊！”

小c大喜，抓起hashmap，把它和链表揉合在了一起。

得到了LinkedHashMap。

“哼哼哼，没用没用，你别忘了还有第二个条件，当存在平局时，最近最少使用的键将被去除。”
电视机上的面具男又出现了。

但小c笑了。
“别想吓我，我已经知道了。”

“什么！？”

“存在平局时，最少使用，那不就是又是一个LRU链表吗！只是链表的修改方式是加入队首，而非相邻修改。”

小c抓起一个hashmap和链表，把它与原本的LinkedHashMap揉合到了一起。

“食我双重hashmap链表啦！！”

“啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊！”

电视机爆炸了。
小c从地下室的废墟中爬了出来。
他用手挡住耀眼的阳光。
感叹道。

“没有内存限制时，用hash就是爽啊。”




**附上代码**

代码中的Layer就是第一层hash用的链表 Node是第二层LRU用的链表

Layer 和 Node类似下图的感觉


**Layer 0(0次的新人) ---Node 0 ---Node 1
|
Layer 1(用了1次) ---Node 0 ---Node 1 ---Node 尾巴 <--新的Node从上层下来时，被加在链表尾巴
|
Layer 2(用了2次) ---Node 0 ---Node 1
|
Layer 45(用了45次)**

用公司比喻的话：

1. 校招的时候，直接增加在0次的新人群里
2. 晋升的时候，从layer跳到下一个layer
3. 裁员的时候，就选择新人里，靠近Node头的开始裁


这样是不是很形象了  \( ❛ ڡ ❛ )/


```
class LFUCache:
    # 用于记录最后使用时间的链表 
    class Node:
        def __init__(self, key: int):
            self.prev = None
            self.next = None
            self.key = key

        def add(self, node):
            self.next = node
            node.prev = self

        def delete_self(self):
            if self.next is not None:
                self.next.prev = self.prev
            if self.prev is not None:
                self.prev.next = self.next

    # 用于记录使用次数的链表
    class Layer:
        def __init__(self, depth: int):
            self.prev = None
            self.next = None
            # depth表示使用次数
            self.depth = depth

            # 这个就是二级的hashmap 加上下面的二级链表 做成了LRU的缓存
            self.queue = {}
            # 二级链表头
            self.start = LFUCache.Node(-1)
            # 二级链表尾巴
            self.end = self.start

    def __init__(self, capacity: int):
        self.capacity = capacity

        # 这个就是一级的hashmap 加上下面的链表 做成了LFU的缓存
        self.data = {}
        # 这个map用于指向链表结点，如果重新设计的话，可以和上面的map合并的
        self.kToLayer = {}
        # 链表尾巴
        self.end_layer = None
        # 链表头
        self.top_layer = self.Layer(0)

    def get(self, key: int) -> int:
        r = self.data.get(key, -1)
        if r != -1:
            # 更新记录使用次数的链表
            self.kToLayer[key] = self.update_layer(self.kToLayer[key], key)
        return r

    def put(self, key: int, value: int) -> None:
        # 1. capacity为0的话直接不干了
        if self.capacity == 0:
            return
        # 2. 数据已经存在的话，就更新记录使用次数的链表
        if self.data.get(key) is not None:
            self.data[key] = value
            self.kToLayer[key] = self.update_layer(self.kToLayer[key], key)
            return

        # 3.1 如果超过了限度，就从链表头取出一个，删掉
        if len(self.data) >= self.capacity:
            key_to_del = self.pop_queue_from_layer(self.top_layer)
            self.data.pop(key_to_del)
            now = self.kToLayer[key_to_del]
            if len(now.queue) == 0 and now.depth > 0:
                self.clear_layer(now)
            self.kToLayer.pop(key_to_del)
        # 3.2 把新的加进去
        self.data[key] = value
        self.add_key_to_layer(self.top_layer, key)
        self.kToLayer[key] = self.top_layer

    # --------------下面都是链表操作的辅助方法，注意链表的穿插不要丢了节点---------------

    def add_key_to_layer(self, now: Layer, key: int):
        n = self.Node(key)
        now.queue[key] = n
        now.end.add(n)
        now.end = n

    def delete_key_of_layer(self, layer: Layer, key: int):
        node = layer.queue[key]
        if node == layer.end:
            layer.end = node.prev
        node.delete_self()
        layer.queue.pop(key)

    # 一级链表的更新（layer更新）
    def update_layer(self, now: Layer, key: int) -> Layer:
        self.delete_key_of_layer(now, key)

        # 注意那个depth+1 就是对应着频次的+1。ps 如果增加的值不定，就不应该用链表了，可能需要红黑树了
        # 1. 当前已是链表最后 即频次最高 ->需要创建新的layer
        if now.next is None:
            next_layer = self.Layer(now.depth + 1)
            self.add_key_to_layer(next_layer, key)
            self.insert_layer(now, next_layer)
            out = next_layer
        # 2. 下一个layer直接跨了好几个深度 ->需要创建新的layer
        elif now.next.depth > now.depth + 1:
            next_layer = self.Layer(now.depth + 1)
            self.add_key_to_layer(next_layer, key)
            self.insert_layer(now, next_layer)
            out = next_layer
        # 3. 下一个layer刚好是目标深度 ->不需要创建新的layer
        else:
            self.add_key_to_layer(now.next, key)
            out = now.next

        # 如果这一层空了，就把它删掉，节省空间
        if len(now.queue) == 0 and now.depth > 0:
            self.clear_layer(now)
        return out

    def insert_layer(self, now: Layer, target: Layer):
        if now.next is None:
            target.prev = now
            now.next = target
            self.end_layer = target
        else:
            target.prev = now
            target.next = now.next
            now.next.prev = target
            now.next = target

    def clear_layer(self, now: Layer):
        if now.next is None:
            now.prev.next = None
            self.end_layer = now.prev
        elif now.prev is None:
            now.next.prev = None
        else:
            now.prev.next = now.next
            now.next.prev = now.prev

    def pop_queue_from_layer(self, now: Layer) -> int:
        # 传进来时就是一级链表头了
        # for top layer
        if len(now.queue) == 0 and now.depth == 0:
            now = now.next

        # 取二级链表的第一个key
        key = now.start.next.key
        self.delete_key_of_layer(now, key)

        if len(now.queue) == 0 and now.depth > 0:
            self.clear_layer(now)
        return key
```
