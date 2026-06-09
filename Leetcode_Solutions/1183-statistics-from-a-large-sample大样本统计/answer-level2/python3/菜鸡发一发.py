```
class Solution(object):
    def sampleStats(self, count):
        """
        :type count: List[int]
        :rtype: List[float]
        """
        all_cou = sum(count)

        sum1 = 0
        min1 = 256
        max1 = 0
        count1 = 0
        index1 = 0
        index2 = 0
        flag = 0
        flag1 = 0
        max_v = 0
        max_i = 0
        for i, j in enumerate(count):
            if j != 0 and min1 > i:
                min1 = i
            if j != 0 and max1 < i:
                max1 = i
            sum1 += i * j
            if flag == 0 and count1 + j >= (all_cou // 2):
                index1 = i
                flag = 1
            if flag1 == 0 and count1 + j >= (all_cou // 2 + 1):
                index2 = i
                flag1 = 1
            count1 += j
            if max_v < j:
                max_v = j
                max_i = i

        if all_cou % 2 == 0:
            median = (float(index1) + float(index2)) / 2
        else:
            median = float(index1)
        return [float(min1), float(max1), float(sum1) / float(all_cou), float(median), float(max_i)]
        

```
