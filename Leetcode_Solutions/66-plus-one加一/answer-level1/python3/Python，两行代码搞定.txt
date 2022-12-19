    def plusOne(self, digits: List[int]) -> List[int]:
        
        num = int(''.join([str(e) for e in digits]))
        return [int(e) for e in str(num+1)]