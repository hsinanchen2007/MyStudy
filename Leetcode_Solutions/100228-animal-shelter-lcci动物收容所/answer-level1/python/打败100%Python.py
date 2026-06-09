![image.png](https://pic.leetcode-cn.com/8d1ebc589cb53fa31e5dc6ee3fb7f5bc106facc1147477e07a1c4d73e89fd240-image.png)
```
class AnimalShelf(object):

    def __init__(self):
        self.animal_shelf = []
        


    def enqueue(self, animal):
        """
        :type animal: List[int]
        :rtype: None
        """
        self.animal_shelf.insert(0,[animal[0],animal[1]])



    def dequeueAny(self):
        """
        :rtype: List[int]
        """
        if len(self.animal_shelf) == 0:
            return [-1,-1]
        return self.animal_shelf.pop()


    def dequeueDog(self):
        """
        :rtype: List[int]
        """
        i = len(self.animal_shelf) - 1
        while i >= 0:
            animal = self.animal_shelf[i]
            if animal[1] == 1:
                ret = animal
                del self.animal_shelf[i]
                return ret
            i -= 1
        return [-1,-1]


    def dequeueCat(self):
        """
        :rtype: List[int]
        """
        i = len(self.animal_shelf) - 1
        while i >= 0:
            animal = self.animal_shelf[i]
            if animal[1] == 0:
                ret = animal
                del self.animal_shelf[i]
                return ret
            i -= 1
        return [-1,-1]


```
