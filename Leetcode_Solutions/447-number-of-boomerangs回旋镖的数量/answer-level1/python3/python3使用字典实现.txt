采用哈希表，设置默认值为0，将距离设置成键，出现过的次数设置为值，由于顺序可以改变，所以每出现一次重复的距离就要*2之前出现过的次数
class Solution:
    def len(self, p1, p2):
        x=p1[0]-p2[0]
        y=p1[1]-p2[1]
        return x*x + y*y
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        count = 0
        hashmap = {}
        for p in points:
            for x in points:
                if x is not p:
                    l = self.len(p, x)
                    count += hashmap.get(l, 0) * 2
                    hashmap[l] = hashmap.get(l, 0) + 1
            hashmap.clear()
        return count

此外还有一种方法，采用三重循环，但是测试py3会超时，不知道其他语言是否是这样