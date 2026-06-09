        n = str(N)
        mapping = {0:0, 1:1, 6:9, 8:8, 9:6}
        ans, m = 0, 1
        for i in n:
            if int(i) not in mapping:
                return False
            else:
                ans +=m * mapping[int(i)]
                m *=10
        if ans == N:
            return False
        else:
            return True