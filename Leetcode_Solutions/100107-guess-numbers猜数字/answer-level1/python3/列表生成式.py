def game(self, guess: List[int], answer: List[int]) -> int:
        res = [i for i in guess if i == answer.pop(0)]
        return len(res)