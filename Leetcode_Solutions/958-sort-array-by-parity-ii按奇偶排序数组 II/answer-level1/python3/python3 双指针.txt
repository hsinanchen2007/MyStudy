    def sortArrayByParityII(self, A: List[int]) -> List[int]:
      head = 0
      tail = head
      while head < len(A):
          if A[tail] % 2 == head % 2:
              A[head], A[tail] = A[tail], A[head]
              head += 1
          elif A[head] % 2 == head % 2:
              head += 1
              tail = head
          else:
              tail += 1
      return A