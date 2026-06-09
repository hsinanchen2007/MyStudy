        if n <= 0:
            return False
        while n > 1:
            right_n = n >> 1
            left_n = right_n << 1
            if left_n != n:
                return False
            n >>= 1
        return True