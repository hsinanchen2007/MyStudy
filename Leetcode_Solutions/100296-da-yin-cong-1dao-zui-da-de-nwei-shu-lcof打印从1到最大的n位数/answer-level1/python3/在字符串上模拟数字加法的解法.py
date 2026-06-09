    def add_num(char):
        for i in range(len(char) - 1, -1, -1):
            if char[i] < '9':
                char = char[:i] + str(int(char[i]) + 1) + char[i + 1:]
                break
            else:
                char = char[:i] + '0' + char[i + 1:]
        return char

    def print_num(char):
        while len(char) > 1 and char[0] == '0':
            char = char[1:]
        return char

    char = '0' * n
    max_char = '9' * n
    res = []
    while char != max_char:
        char = add_num(char)
        new_char = print_num(char)
        print(new_char)
        res.append(new_char)
    return res