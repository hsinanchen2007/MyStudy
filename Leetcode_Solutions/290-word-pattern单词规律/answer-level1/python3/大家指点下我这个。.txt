class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        a = self.generate(pattern)
        b = self.generate(str.split(" "))
        if a ==b:
            return True
        else:
            return False

    @staticmethod
    def generate(value):
        _dict = dict()
        for i,v in enumerate(value):
            _dict.setdefault(v,list()).append(i)
        return list(_dict.values()