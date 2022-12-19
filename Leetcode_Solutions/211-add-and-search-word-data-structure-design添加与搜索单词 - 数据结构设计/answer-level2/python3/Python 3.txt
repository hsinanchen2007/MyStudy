class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dictionary = {}
        self.setEnd = False

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        now = self
        for letter in word:
            if letter in now.dictionary:
                now = now.dictionary[letter]
            else:
                now.dictionary[letter] = WordDictionary()
                now = now.dictionary[letter]
        now.setEnd = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        if len(word) == 0 and self.setEnd:
            return True
        now = self

        for letter in word:
            if letter == '.':
                for node in self.dictionary.values():
                    if(node.search(word[1:])):
                        return True
            else:
                if letter not in self.dictionary:
                    return False
                return self.dictionary[letter].search(word[1:])
        return False