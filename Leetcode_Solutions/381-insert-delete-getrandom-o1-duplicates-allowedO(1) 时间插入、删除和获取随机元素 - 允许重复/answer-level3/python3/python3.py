    import random
    class RandomizedCollection(object):

        def __init__(self):
            """
            Initialize your data structure here.
            """
            # list维护 添加的元素
            # dict的键值对维护 元素的存在和索引位置
            self.d = {}
            self.l = []
            

        def insert(self, val):
            """
            Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
            :type val: int
            :rtype: bool
            """
            if val not in self.d:
                self.d[val] = [len(self.l)]
                self.l.append(val)
                return True
            else:
                self.d.get(val).append(len(self.l))
                self.l.append(val)
                return False
            

        def remove(self, val):
            """
            Removes a value from the collection. Returns true if the collection contained the specified element.
            :type val: int
            :rtype: bool
            """
            if self.d.get(val):
                # 如果目标值在最后一个，就不能与前面的值交换， 需要直接pop
                if self.l[-1] == val:
                    self.d.get(val).remove(len(self.l)-1)
                    self.l.pop()
                    
                else:
                    # pop(val) 的一个索引， 把最后一个元素移到index位置，并更新最后一个元素的索引，pop最后一个元素
                    index = self.d.get(val).pop()

                    last_val = self.l[-1]
                    self.l[index] = last_val

                    self.d.get(last_val).remove(len(self.l)-1)
                    self.d.get(last_val).append(index)
                    
                    self.l.pop()
                
                # 如果self.d[val] == [], 则移除self.d[val]
                if not self.d[val]:
                        del self.d[val]   
                        
                return True
            else:
                return False
            
            
            
            

        def getRandom(self):
            """
            Get a random element from the collection.
            :rtype: int
            """
            return random.choice(self.l) -->