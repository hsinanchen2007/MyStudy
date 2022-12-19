class Solution:
    def countBits(num):
        """
        bits[i] = bits[i & (i - 1)] + 1.
        i & (i - 1)：清除i二进制最后的1
        """
        bits = [0]
        for i in range(1, num + 1):
            bits.append(bits[i & (i - 1)] + 1)
        return bits

....