```
class LRUCache:
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.stack = list()
        self.cache = dict()

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.cache:
            self.stack.remove(key)
            self.stack.append(key)
            return self.cache[key]
            
        return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self.cache:
            self.stack.remove(key)  
        else:
            if len(self.cache) == self.capacity:
                del self.cache[self.stack[0]]
                self.stack.pop(0)
                
        self.stack.append(key)
        self.cache[key] = value

        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```
