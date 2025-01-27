# Test Cases for rods.c 

## Test Case 1: Input and Output Correct 

**Description** Shows the correct answers with valid input and presents correct output. 

**Input**
- Rod: 45
- Rod lengths: [2, 3, 5]
- Values: [4, 8, 10]

**Expected Output**
Cutting list:
22 @ 2 = 88
Remainder: 1
Value of rod: 88

Cutting list:
15 @ 3 = 120
Remainder: 0
Value of rod: 120

Cutting list:
9 @ 5 = 90
Remainder: 0
Value of rod: 90

Best value : 120


## Test Case 2: Second Command Line Argument

**Description** Tests to see if there is a second command line argument when you run rods.c

**Input**
- Rod: ' '
- Rod lengths: 
- Values: 

**Expected Output**
Second argument not found. To run program, do -->  ./rods <length>


## Test Case 3: Rod Length is Greater Than 0

**Description** Test the program with a negative rod length. 

**Input**
- Rod: -2
- Rod lengths: 
- Values: 

**Expected Output**
Length of rod must be greater than 0

## Test Case 4: No Rod Length

**Description** Test the program if no rod lengths and values are given. 

**Input**
- Rod: 23
- Rod lengths: []
- Values: []

**Expected Output**
No pieces entered

## Test Case 5: Single Rod Length

**Description** Test the program if a single rod length and value are given. 

**Input**
- Rod: 23
- Rod lengths: [2]
- Values: [3]

**Expected Output**
Cutting list:
11 @ 2 = 33
Remainder: 1
Value of rod: 33

Best value : 33