```
if list(collections.Counter(list(pattern)).values()) == list(collections.Counter(str.split(" ")).values()):
            return True
        else:
            return False
```
