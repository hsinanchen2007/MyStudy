class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        secret, guess = list(secret), list(guess)

        a = b = 0
        # 先解决相同位置相同的值，再设置值为None
        for i in range(len(guess)):
            if guess[i] == secret[i]:
                secret[i] = guess[i] = None
                a += 1

        # 再结局不同位置相同的数，并设置两个的值为None
        for i in range(len(guess)):
            if guess[i] in secret and guess[i] != secret[i]:
                secret[secret.index(guess[i])] = None
                guess[i] = None
                b += 1
        return '{}A{}B'.format(a, b)