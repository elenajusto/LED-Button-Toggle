# Picture of Circuit
![image](https://github.com/elenajusto/LED-Button-Toggle/assets/56148816/841eff54-05fd-4693-842b-abe622f574d4)

# Approach
We want to be able to send an output to Port D7 and read from Port D6 on the AVR Atmega328 microcontroller.

This means we want to access the Port D Data Register on the Atmega328p.

![image](https://github.com/elenajusto/LED-Button-Toggle/assets/56148816/46f4e60d-16a2-499e-bc7f-3857f5d6c4a5)

We need to use the Data Direction Register for Port D (DDRD) and set:
	• Port D7: Output
	• Port D6: Input

Then we need to write code that will read what the voltage value at Port D6 is.

Then we need to write code that will, when Port D6 has a voltage high reading, will output a voltage high signal at Port D7.

The code will have to stop outputting voltage high at Port D7 if Port D6 reading returns to voltage low.

![image](https://github.com/elenajusto/LED-Button-Toggle/assets/56148816/2daf39d4-420b-4550-9dab-2b6036e20015)

So we want DDD7 to set PORTD7 to WRITE (OUTPUT).

And we want DDD6 to set PORTD6 to READ (INPUT).

![image](https://github.com/elenajusto/LED-Button-Toggle/assets/56148816/1d78c3d3-ef6c-4d02-811e-8decfebcbb61)

# Pseudocode Planning

// Setting DDRD to 0b10000000
Since DDRD is by default:  0b00000000
And we want DDRB:           0b10000000

We get a variable X = 0b10000000

We apply variable X to DDRD using the OR (|) operator
--> DDRD              |=    X
--> DDRD              OR   X
--> 0b00000000  OR   0b10000000
--> 0b10000000

What this looks like is:
X = 0b10000000
DDRD = DDRD | X

// Once DDRD has been set, we have:
// PD7 can do output
// PD6 can do input
// We now write the code that will allow sensing of 
// button push to decide when to output form PD7

START
If PD6 == 1 THEN
	Set PD7 == 1
ELSE
	SET PD7 == 0
END
