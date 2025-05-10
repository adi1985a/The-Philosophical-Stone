#include <iostream>
#include <string>
#include "ascii_art.h"
#include "game_utils.h"

using namespace std;

string wybor;
PlayerState player;

int main() {
    ios_base::sync_with_stdio(false);
    SetConsoleTitle("The Philosophical Stone");

wstep:
    GameUtils::clearScreen();
    GameUtils::setColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n\n" << ascii_art::TITLE_SCREEN << "\n\n";
    GameUtils::printSlowly("Welcome to the Philosophical stone.", 50);
    GameUtils::printSlowly("Game created by: Adrian Lesniak", 50);
    GameUtils::printSlowly("\nPress any key to start!", 50);
    GameUtils::wait();
    GameUtils::clearScreen();

pomieszczenie1:
    GameUtils::clearScreen();
    GameUtils::displayStats(player);
    GameUtils::printSlowly("Room 1: The Cell", 30);
    
    cout << "\nImagine you wake up suddenly in a place you don't know at all, " << endl;
    cout << "And which looks like the dungeons of the historic castle." << endl;
    cout << "The door to the cell in which you are in is unfortunately closed." << endl;
    cout << "Next to you stands a large, medieval sideboard with decorations." << endl;
    cout << "The sideboard has two doors and one, large drawer." << endl;
    cout << "On the left door a golden inscription was engraved in the Old Greek language: doubt." << endl;
    cout << "On the right door there is a silver inscription: surprise," << endl;
    cout << "And on the drawer: awareness, red." << endl;

pomieszczenie1a:
    GameUtils::displayStats(player);
    GameUtils::setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\nWhat will you do now? "<< endl;
    cout << "\na. You open the left door of the dresser." << endl;
    cout << "b. You open the right door of the dresser." << endl;
    cout << "c. You open a drawer." << endl;
    cout << "d. You shout: Help! And you wait if someone will finally appear." << endl;
    cout << "\ne. Examine the cell walls carefully" << endl;
    cout << "f. Meditate to restore sanity" << endl;
    cout << "\nYour choice (press the correct letter and confirm with the Enter key): "<< endl;
    cin >> wybor;

    if (!GameUtils::processChoice(wybor, player)) {
        cout << "Invalid choice, please try again" << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie1a;
    }

    if (wybor=="a") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "Unfortunately, you find nothing inside." << endl;
        cout << "\nPress any key to go back." << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie1a;
    }

    if (wybor=="b") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "\aTo your surprise, a poisonous snake hid inside, which sprang out, digging its sharp fangs into your leg."<<endl;
        player.damage(10); // Snake now only does 10% damage
        GameUtils::delay(2000); // Show damage effect
        if (player.health <= 0) {
            cout << "\nYou succumbed to the snake's venom..." << endl;
            return 0;
        }
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie1a;
    }

    if (wybor=="c") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "You find a golden key with which you open the door and go up the stairs that go up high." <<endl;
        cout << "\nPress any key to go back." << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie2;
    }

    if (wybor=="d") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "After a few minutes of calling, a hooded person in a monk's suit appears on the other side of the dungeon door." << endl;
        cout << "It's too dark to see who he is, but you can see him pointing at the dresser." << endl;
        cout << "Looks at you for a moment, then walks away, leaving you alone in the cold dungeon again." << endl;
        cout << "\nPress any key to go back." << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie1a;
    }

    if (wybor=="e") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        GameUtils::printSlowly("You discover ancient runes carved into the walls...");
        player.changeSanity(-10);
        if (player.sanity < 30) {
            cout << "Your mind starts to crack under the weight of ancient knowledge..." << endl;
            player.damage(20);
        }
        GameUtils::wait();
        goto pomieszczenie1a;
    }

    if (wybor=="f") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        GameUtils::printSlowly("You sit down and start meditating, feeling your sanity slowly returning...");
        player.sanity += 20;
        // ...continue with new story branch
    }

    else {
        cout<<"You entered a wrong value, please try again"<< endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie1;
    }

pomieszczenie2:
    GameUtils::clearScreen();
    GameUtils::displayStats(player);
    cout << "Room 2: King's Bedroom." << endl;
    cout << "\nThe stairs lead you to a chamber that looks like a royal bedroom." << endl;
    cout << "You look around a large room, you are alone here, getting more and more confused." << endl;
    cout << "In front of you you see a huge canopy king bed with a pentagram painted on it,"<< endl;
    cout << "on the left side a small, decorated chest of drawers with the inscription: Everything is a number and a comfortable velor armchair next to it," << endl;
    cout << "and on the right there is an open window, from which you can hear the sound of the sea and the sound of waves hitting the rocks." <<endl;

pomieszczenie2a:
    GameUtils::displayStats(player);
    GameUtils::setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\nWhat will you do now?" << endl;
    cout << "\na. You open the dresser."<< endl;
    cout << "b. You are lying on the king's bed." << endl;
    cout << "c. You return to the dungeon by taking the stairs back." << endl;
    cout << "d. You are approaching the window." << endl;
    cout << "\nYour choice (press the correct letter and confirm with ENTER):" << endl;
    cin >> wybor;

    if (wybor=="a") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "In the chest of drawers you find a piece of paper with a painted triangle and the inscription below it: Get out." << endl;
        cout << "\nPress any key to go back." << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie2a;
    }

    if (wybor=="b") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "The bed is collapsing slowly down with you by some mechanism you accidentally activated." <<endl;
        cout << "\nPress any key to continue!" << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie3;
    }

    if (wybor=="c") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "You are back in your cell with the door locked." << endl;
        cout << "It's like time went back to when you first woke up here." <<endl;
        cout << "\nPress any key to continue!" << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie1a;
    }

    if (wybor=="d") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "You look down from the window. Below you see the sea and rocks." << endl;
        cout << "You are very high and you will not be able to descend without the proper equipment." <<endl;
        cout << "You turn around looking for a rope or something that might help you." << endl;
        cout << "Unfortunately, you're doing it too fast and you're losing your balance," << endl;
        cout << "then you fly out the window and land on the razor-sharp rocks below." <<endl;
        cout << "\nPress any key." << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        cout << "\aUnfortunately you die and the game ends." << endl;
        return (0);
    }

    else {
        cout<<"You entered a wrong value, please try again"<< endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie2;
    }

pomieszczenie3:
    GameUtils::clearScreen();
    GameUtils::displayStats(player);
    cout << "Room 3: Secret Passage." << endl;
    cout << "\nAfter a few seconds the bed stops collapsing and you are in a dark room." << endl;
    cout << "You raise your head and look around. Suddenly you see a small flame in front of you,"<< endl;
    cout << "like a torch approaching you slowly." << endl;
    cout << "You don't feel any more anxiety or fear." << endl;
    cout << "The closer the flame is, the more pleasure you feel, your head stops hurting," << endl;
    cout << "your mind clears up and you realize you've never felt before" << endl;
    cout << "such happiness as right now, in this abstract situation." << endl;
    cout << "When the flame is a meter away you feel like this moment could last forever." <<endl;
    cout << "The torch illuminates the figure of the hooded person holding it." <<endl;
    cout << "The man in the monk's robes looks up at you and in a low voice calls you:" << endl;
    cout << "If you want to prevent evil, but you can't, and people must free themselves from fear of you and death" << endl;
    cout << "and yet you do not punish them or reward them.. then who are you?" << endl;

pomieszczenie3a:
    GameUtils::displayStats(player);
    GameUtils::setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\nWhat will you do now?" << endl;
    cout << "\na. You will humbly lower your head and whisper: Human." << endl;
    cout << "b. Snatch the torches from his hands and hit him with all your might." << endl;
    cout << "c. Grab a torch and raise it to the air and say aloud: God." << endl;
    cout << "d. You jump off the bed, pushing the monk away and start running towards the dark abyss in front of you." << endl;
    cout << "\nYour choice (press the correct letter and confirm with ENTER):" << endl;
    cin >> wybor;

    if (wybor=="a") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "The monk lowers his head, turns around and walks away." << endl;
        cout << "You start calling after him, but suddenly the bed you're lying on starts plummeting down." <<endl;
        cout << "When you fall for a long time, you lose consciousness and wake up in the cell where you started your adventure." <<endl;
        cout << "\nPress any key to continue!" << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie1a;
    }

    if (wybor=="b") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "The monk falls, and you leap vigorously from the bed and run forward in complete darkness, lighting your way with the captured torch." <<endl;
        cout << "After a few minutes you notice that the torch is starting to go out" << endl;
        cout << "You can't see anything anymore and your fear is so strong that your whole body starts to tremble." << endl;
        cout << "You feel like you're running out of oxygen, you breathe slower and slower until you run out of breath and die falling down," << endl;
        cout << "but luckily you don't know that anymore." << endl;
        cout << "\nPress any key." << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        cout << "\aUnfortunately you die and the game ends." << endl;
        return (0);
    }

    if (wybor=="c") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "The torch in your hand is getting brighter and brighter" << endl;
        cout << "illuminating a huge ballroom with huge crystal chandeliers." << endl;
        cout << "Before you is like a spectacle of shadows dancing on the wall." <<endl;
        cout << "You can't see people, and you can't hear music. You get off the bed and walk closer to the wall of shadows." <<endl;
        cout << "\nPress any key to continue!" << endl;
        GameUtils::wait();
        goto pomieszczenie4;
    }

    if (wybor=="d") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "After a few minutes of running, endless darkness and overwhelming emptiness." << endl;
        cout << "You lose consciousness and become restless again, suddenly your path ends and you fall into the abyss." << endl;
        cout << "As you fall, you close your eyes and land suddenly softly on the bed in the king's bedroom." <<endl;
        cout << "The bed begins to slowly descend again" << endl;
        cout << "\nPress any key to continue!" << endl;
        GameUtils::wait();
        goto pomieszczenie3;
    }

    else {
        cout<<"You entered a wrong value, please try again"<< endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie3;
    }

pomieszczenie4:
    GameUtils::clearScreen();
    GameUtils::displayStats(player);
    cout << "Room 4: Ballroom." << endl;
    cout << "\nAs you get closer, the wall starts to gray and the shadows of waltzing couples" << endl;
    cout << "turn into the shadows of people fighting with each other, twisted and brutal." << endl;
    cout << "Above them is the inscription: Panta rhei, and a mysterious golden talisman appears in your hand." << endl;
    cout << "The talisman has three buttons and a warning:" << endl;
    cout << "Choose wisely, only enlightened can leave the cave, the rest will perish." << endl;
    cout << "The first button says: real world," << endl;
    cout << "on the second: a homogeneous world, and on the third: an ideal world." <<endl;

pomieszczenie4a:
    GameUtils::displayStats(player);
    GameUtils::setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\nWhat will you do now?" << endl;
    cout << "\na. You press the first button that says: real world." << endl;
    cout << "b. You press the second button that says: homogeneous world." << endl;
    cout << "c. You press the first and third buttons with inscriptions: real and ideal world." << endl;
    cout << "d. You press the second and third buttons with inscriptions: homogeneous and ideal world." << endl;
    cout << "\nYour choice (press the correct letter and confirm with ENTER):" << endl;
    cin >> wybor;

    if (wybor=="a") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "You are woken up in your bed by the sound of the morning alarm, you are free," << endl;
        cout << "but you haven't fully discovered the secrets of the castle." <<endl;
        cout << "\nPress any key." << endl;
        GameUtils::wait();
        cout << "\aUnfortunately, the game is over." <<endl;
        return (0);
    }

    if (wybor=="b") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "You turn into a statue and are trapped here forever." <<endl;
        cout << "\nPress any key." << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        cout << "\aUnfortunately, the game is over." << endl;
        return (0);
    }

    if (wybor=="c") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "The talisman starts making strange sounds and the vision of cruel war on the wall disappears." << endl;
        cout << "The door you exit through then appears on it."<<endl;
        cout << "A panorama of the ancient city square appears in front of you." <<endl;
        cout << "The city is full of life." << endl;
        cout << "\nPress any key to continue!" << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie5;
    }

    if (wybor=="d") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "You turn into a shadow on the wall and start your eternal dance," << endl;
        cout << "you are now part of this mysterious place," << endl;
        cout << "but you are no longer allowed to discover its secrets." <<endl;
        cout << "\nPress any key." << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        cout << "\aUnfortunately, the game ends." << endl;
        return (0);
    }

    else {
        cout<<"You entered a wrong value, please try again"<< endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie4;
    }

pomieszczenie5:
    GameUtils::clearScreen();
    GameUtils::displayStats(player);
    cout << "Room 5: Ancient City." << endl;
    cout << "\nThe residents do not pay attention to you, they pass by indifferently,"<< endl;
    cout << "they talk to each other, haggle at the market, banter and laugh out loud." << endl;
    cout << "You see one person in the crowd walking towards you with a smile on his face." << endl;
    cout << "You recognize him from history class, Marcus Aurelius. He stops by you and says:" << endl;
    cout << "It will be as easy as losing her. What makes you happy?" <<endl;

pomieszczenie5a:
    GameUtils::displayStats(player);
    GameUtils::setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\nWhat will you do now?" << endl;
    cout << "\na. You don't answer anything, you just return Marcus Aurelius' smile at him." << endl;
    cout << "b. You answer: Happiness gives a man only his morality." << endl;
    cout << "c. You answer: Happiness is what gives a man only his empathy." << endl;
    cout << "d. You answer: Only virtue gives a man happiness." << endl;
    cout << "\nYour choice (press the correct letter and confirm with ENTER):" << endl;
    cin >> wybor;

    if (wybor=="a") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "Marcus Aurelius looks at you and his smile widens,"<< endl;
        cout << "grabs your hand misreading your intentions and drags you to a nearby building." << endl;
        cout << "You break away from him and run towards the crowd," << endl;
        cout << "which suddenly turns into a thick mist and it engulfs you whole." << endl;
        cout << "You close your eyes and wake up in a bed in a royal bedroom." << endl;
        cout << "The bed is starting to collapse again." << endl;
        cout << "\nPress any key to continue!" << endl;
        GameUtils::wait();
        goto pomieszczenie2;
    }

    if (wybor=="b") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "Marcus Aurelius nods his head in the affirmative, and after a short while says:" << endl;
        cout << "I agree with you, but this is not the answer I was looking for." << endl;
        cout << "\nPress any key to continue!" << endl;
        GameUtils::wait();
        goto pomieszczenie5a;
    }

    if (wybor=="c") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "Marcus Aurelius nods his head in the affirmative, and after a short while says:" << endl;
        cout << "I agree with you, but this is not the answer I was looking for." <<endl;
        cout << "\nPress any key to continue!" << endl;
        GameUtils::wait();
        goto pomieszczenie5a;
    }

    if (wybor=="d") {
        GameUtils::clearScreen();
        GameUtils::displayStats(player);
        cout << "Marcus Aurelius hands you a strange shiny stone and says:" << endl;
        cout << "It's the philosopher's stone you didn't seek but found." <<endl;
        cout << "Now you are ready to wake up!" << endl;
        cout << "Everything starts spinning around you and suddenly you are in your bed" << endl;
        cout << "holding the philosopher's stone in hand." <<endl;
        cout << "It's daytime outside and you can hear the sounds of the city waking up, it's stuffy." << endl;
        cout << "Sorry, you can't get out of bed to open the window." << endl;
        cout << "The stone you're holding is getting heavier and heavier, but you can't let go of it," << endl;
        cout << "you feel like your hand isn't yours and it's making decisions on its own." << endl;
        cout << "Outdoors is suddenly dark, hearing terrifying screams and sounds of panic." << endl;
        cout << "The floor in your bedroom starts to tremble, bits of plaster fall from the ceiling." << endl;
        cout << "You must leave immediately..!" << endl;
        cout << "\nPress any key." << endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        cout << "Congratulations, you win the game! To be continued." << endl;
        return (0);
    }

    else {
        cout<<"You entered a wrong value, please try again"<< endl;
        GameUtils::wait();
        GameUtils::clearScreen();
        goto pomieszczenie1;
    }

    return 0;
}
