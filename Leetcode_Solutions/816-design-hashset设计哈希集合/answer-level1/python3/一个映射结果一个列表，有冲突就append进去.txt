class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.number = 1000
        self.buckets = [[] for _ in range(self.number)]
    def add(self, key: int) -> None:
        
            y = key % self.number
            if key not in self.buckets[y]:
                self.buckets[y].append(key)
           

    def remove(self, key: int) -> None:
        y = key % self.number
        
        if key in self.buckets[y]:
            self.buckets[y].remove(key)
    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        y = key % self.number
        if key in self.buckets[y]:
            return True
        else:
            return False