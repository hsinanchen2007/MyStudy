这个题为啥是困难啊？是因为大家都懒得写吗？
好吧，看官方复杂题解解释的头头是道，咱也不知道有啥必要。稍微解释下。
维护了2个哈希表，其中 _filesystem 是实际的文件系统，而 pathhash 则是为了快速索引。
简单的来说，新建的路径时，每更深一级，都会把当前路径存入 pathhash，将 _filesystem 种对应的目录链接过来。
这样的好处就是 ls 和 read 的时候会非常快，不论多深，我的路径是完全在一个 hashtable 里，存储是扁平的。别管多深，只要存在，索引是 O(0)。

有一处强迫症的地方是，文件的内容，只存在 pathhash 其实就可以？现在这样相当于存了2遍？不过内存应该是一样的。如果只存在 pathhash 里，两个 dict 的功能看起来就稍微有些混乱。

```python
class FileSystem:
    def __init__(self):
        self._filesystem = {}
        self.pathhash = {'/': self._filesystem}

    def ls(self, path: str) -> List[str]:
        if isinstance(self.pathhash[path], str):
            return [path.rsplit('/', 1)[1]]
        return sorted(list(self.pathhash[path]))

    def mkdir(self, path: str) -> None:
        paths, root, cur = filter(''.__ne__, path.split('/')), self._filesystem, ''
        for p in paths:
            cur += '/' + p
            if cur not in self.pathhash:
                root[p] = {}
                self.pathhash[cur] = root[p]
            root = root[p]

    def addContentToFile(self, filePath: str, content: str) -> None:
        path, fname = filePath.rsplit('/', 1)
        if path == '':
            path = '/'
        if path not in self.pathhash:
            self.mkdir(path)
        folder = self.pathhash[path]
        if fname not in folder:
            folder[fname] = ''
        folder[fname] += content
        self.pathhash[filePath] = folder[fname]

    def readContentFromFile(self, filePath: str) -> str:
        return self.pathhash[filePath]


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
```