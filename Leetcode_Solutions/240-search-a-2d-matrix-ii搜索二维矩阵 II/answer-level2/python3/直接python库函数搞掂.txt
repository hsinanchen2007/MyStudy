        for i in range(len(matrix)):
            try:
                matrix[i].index(target)
            except:
                continue
            else:
                return True

        return False