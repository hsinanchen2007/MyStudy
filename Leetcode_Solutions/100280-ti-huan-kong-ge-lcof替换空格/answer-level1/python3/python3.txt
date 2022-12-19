class Solution:
    def replaceSpace(self, s: str) -> str:
        new_s = ""
        for char in s:
            if char == " ":
                new_s += "%20"
            else:
                new_s += char

        return new_s