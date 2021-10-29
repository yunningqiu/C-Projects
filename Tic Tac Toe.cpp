#include "ccc_win.h"
#include <string>

int ccc_win_main()
{
	string response;

	do {

		cwin.clear();

		cwin.coord(-0.5, 3.5, 3.5, -0.5);
		Point m(1, 3), n(1, 0), t(2, 3), h(2, 0), p(0, 2), q(3, 2), r(0, 1), s(3, 1);
		Line mn(m, n), th(t, h), pq(p, q), rs(r, s);
		cwin << mn << th << pq << rs;
		//Change coordination and set up the board

		int count = 0;
		while (count < 9)
		{
			Point wcenter = cwin.get_mouse("Click for Woman.");
			// Ask for a click point for woman

			if (wcenter.get_x() > -0.5 && wcenter.get_x() < 1 && wcenter.get_y() > 2 && wcenter.get_y() < 3.5)
			{
				Point square1(0.5, 2.5);
				wcenter = square1;
			}

			if (wcenter.get_x() > 1 && wcenter.get_x() < 2 && wcenter.get_y() > 2 && wcenter.get_y() < 3.5)
			{
				Point square2(1.5, 2.5);
				wcenter = square2;
			}

			if (wcenter.get_x() > 2 && wcenter.get_x() < 3.5 && wcenter.get_y() > 2 && wcenter.get_y() < 3.5)
			{
				Point square3(2.5, 2.5);
				wcenter = square3;
			}
			
			if (wcenter.get_x() > -0.5 && wcenter.get_x() < 1 && wcenter.get_y() > 1 && wcenter.get_y() < 2)
			{
				Point square4(0.5, 1.5);
				wcenter = square4;
			}

			if (wcenter.get_x() > 1 && wcenter.get_x() < 2 && wcenter.get_y() > 1 && wcenter.get_y() < 2)
			{
				Point square5(1.5, 1.5);
				wcenter = square5;
			}

			if (wcenter.get_x() > 2 && wcenter.get_x() < 3.5 && wcenter.get_y() > 1 && wcenter.get_y() < 2)
			{
				Point square6(2.5, 1.5);
				wcenter = square6;
			}

			if (wcenter.get_x() > -0.5 && wcenter.get_x() < 1 && wcenter.get_y() > -0.5 && wcenter.get_y() < 1)
			{
				Point square7(0.5, 0.5);
				wcenter = square7;
			}

			if (wcenter.get_x() > 1 && wcenter.get_x() < 2 && wcenter.get_y() > -0.5 && wcenter.get_y() < 1)
			{
				Point square8(1.5, 0.5);
				wcenter = square8;
			}

			if (wcenter.get_x() > 2 && wcenter.get_x() < 3.5 && wcenter.get_y() > -0.5 && wcenter.get_y() < 1)
			{
				Point square9(2.5, 0.5);
				wcenter = square9;
			}

			// Detect the click and place them in the center of each square (for extra credit 2)

			Point circlew(wcenter.get_x(), wcenter.get_y() + 0.25);
			Circle woman_circle(circlew, 0.15);
			Point a(wcenter.get_x(), wcenter.get_y() + 0.1);
			Point b(wcenter.get_x(), wcenter.get_y() - 0.4);
			Line ab(a, b);
			Point c(wcenter.get_x() - 0.3, wcenter.get_y());
			Point d(wcenter.get_x() + 0.3, wcenter.get_y());
			Line cd(c, d);
			cwin << ab << cd << woman_circle;
			count += 1;
			// Draw the woman symbol

			if (count < 8)
			{
				Point mcenter = cwin.get_mouse("Click for Man.");
				// Ask for a click point for man

				if (mcenter.get_x() > -0.5 && mcenter.get_x() < 1 && mcenter.get_y() > 2 && mcenter.get_y() < 3.5)
				{
					Point square1(0.5, 2.5);
					mcenter = square1;
				}

				if (mcenter.get_x() > 1 && mcenter.get_x() < 2 && mcenter.get_y() > 2 && mcenter.get_y() < 3.5)
				{
					Point square2(1.5, 2.5);
					mcenter = square2;
				}

				if (mcenter.get_x() > 2 && mcenter.get_x() < 3.5 && mcenter.get_y() > 2 && mcenter.get_y() < 3.5)
				{
					Point square3(2.5, 2.5);
					mcenter = square3;
				}

				if (mcenter.get_x() > -0.5 && mcenter.get_x() < 1 && mcenter.get_y() > 1 && mcenter.get_y() < 2)
				{
					Point square4(0.5, 1.5);
					mcenter = square4;
				}

				if (mcenter.get_x() > 1 && mcenter.get_x() < 2 && mcenter.get_y() > 1 && mcenter.get_y() < 2)
				{
					Point square5(1.5, 1.5);
					mcenter = square5;
				}

				if (mcenter.get_x() > 2 && mcenter.get_x() < 3.5 && mcenter.get_y() > 1 && mcenter.get_y() < 2)
				{
					Point square6(2.5, 1.5);
					mcenter = square6;
				}

				if (mcenter.get_x() > -0.5 && mcenter.get_x() < 1 && mcenter.get_y() > -0.5 && mcenter.get_y() < 1)
				{
					Point square7(0.5, 0.5);
					mcenter = square7;
				}

				if (mcenter.get_x() > 1 && mcenter.get_x() < 2 && mcenter.get_y() > -0.5 && mcenter.get_y() < 1)
				{
					Point square8(1.5, 0.5);
					mcenter = square8;
				}

				if (mcenter.get_x() > 2 && mcenter.get_x() < 3.5 && mcenter.get_y() > -0.5 && mcenter.get_y() < 1)
				{
					Point square9(2.5, 0.5);
					mcenter = square9;
				}
				// Detect the click point and place it at the center of each square (for extra credit 2)

				Point circlem(mcenter.get_x() - 0.1, mcenter.get_y() - 0.1);
				Circle man_circle(circlem, 0.15);
				Point e(mcenter.get_x() + 0.4, mcenter.get_y() + 0.4);
				Line arrow(mcenter, e);
				Point arrowp1(mcenter.get_x() + 0.4, mcenter.get_y() + 0.2);
				Line arrow1(arrowp1, e);
				Point arrowp2(mcenter.get_x() + 0.2, mcenter.get_y() + 0.4);
				Line arrow2(arrowp2, e);
				cwin << man_circle << arrow << arrow1 << arrow2;
				count += 1;
				//Draw the man symbol
			}
		}
	
		response = cwin.get_string("Game over. Play again [y/n]?");
	    } while (response == "y");
		// Repeat the process if user input y after playing once

	if (response == "n")
	{
		cwin.clear();
		Point last(1, 2);
		Message lastsentence(last, "Thanks for playing!");
		cwin << lastsentence;
	}
	// End the game if user input n

	return 0;
}