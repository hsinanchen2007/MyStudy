```python
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        # stack
        # Time complexity : O(N)
        # Space compleixy: O(N)
        symbol_stack = []
        def calculate_symbols(opt, symbols):
            if opt == '|':
                return 't' if 't' in symbols else 'f'
            elif opt == '&':
                return 'f' if 'f' in symbols else 't'
            else:
                return 't' if symbols[0] == 'f' else 'f'

        for e in expression:
            if e == ')':
                symbols = []
                top = symbol_stack.pop()
                while top != '(':
                    symbols.append(top)
                    top = symbol_stack.pop()
                opt = symbol_stack.pop()
                symbol_stack.append(calculate_symbols(opt, symbols))
            elif e == ',':continue
            else: symbol_stack.append(e)
        return True if symbol_stack[-1] == 't' else False
```