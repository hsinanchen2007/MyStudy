class WordsFrequency:

    def __init__(self, book: List[str]):
        word_freq = {}
        for i in book:
            if i in word_freq:
                word_freq[i] += 1
            else:
                word_freq[i] = 1
        self.word_freq = word_freq

    def get(self, word: str) -> int:
        if word in self.word_freq:
            return self.word_freq[word]
        else:
            return 0