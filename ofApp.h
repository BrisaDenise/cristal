#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();


		//Variables generales
		const float ancho = 1920;
		const float alto = 1080;

		float escalaX;
		float escalaY;

		bool b_menu;
		bool b_p_principal;
		bool escena_esc;
		bool escena_mod;
		bool escena_ric;

		ofTrueTypeFont fuente_texto;

		ofVec2f pos_dialogos;

		int linea;


		// VARIABLES -Menú-
		ofImage titulo;
		ofVec2f titulo_pos;

		string empezar;
		ofVec2f empezar_pos;

		string datos;
		ofVec2f datos_pos;



		//VARIABLES -Escena principal HALL-
		ofSoundPlayer amb_principal;

		ofImage p_moda;
		ofVec2f p_moda_pos;
		bool hablar;
		ofSoundPlayer risa;

		string p_moda_dialogo_principio[5];
		string p_moda_dialogo_final[5];
		
		
		ofImage puertas[3]{};
		ofVec2f puertas_pos[3]{};


		string cerrado;
		bool mostrar_mensaje;
		int cont_p;




		//VARIABLES -Escena Esclavos-
		bool abierto_p1;

		ofImage fondo_esc;
		ofSoundPlayer amb_esc;

		ofImage radio;
		ofVec2f radio_pos;
		ofSoundPlayer radio_mus;
		float volumen;
		bool bandera_radio;


		ofImage maq_cocer;
		ofVec2f maq_cocer_pos;
		ofSoundPlayer maq_grito;


		ofImage esclavo[3];
		ofVec2f esclavo_pos[3];
		string dialogo_esc;
		bool hablando_esc;

		string dialogo_esc_miedo[4];
		bool hablando_miedo;


		ofImage nino;
		ofVec2f nino_pos;
		string dialogo_nino[2];
		bool hablando_nino;



		//VARIABLES -Escena modelos-
		bool abierto_p2;

		ofImage fondo_mod[2];
		ofSoundPlayer amb_mod;
		ofSoundPlayer amb_mod_mal;
		bool distorcion;

		ofImage tablet[2];
		ofVec2f tablet_pos;

		ofVideoPlayer tablet_video;
		ofVec2f tablet_video_pos;
		bool reproduciendo_tablet;


		ofImage modelo[6][2];
		ofVec2f modelo_pos[6];
		string frases_mod[7];
		bool hablando_mod;
		int azar;


		ofImage camara[2];
		ofVec2f camara_pos;
		ofSoundPlayer flash;

		int fotos;
		string mod_echar[4];
		


		//VARIABLES -Escena ricos-
		bool abierto_p3;

		ofImage fondo_ric;
		ofSoundPlayer amb_ric;

		ofImage tv;
		ofVec2f tv_pos;
		ofVideoPlayer tv_video;
		ofVec2f tv_video_pos;

		ofImage ricos[5];
		ofVec2f ricos_pos[5];

		ofImage mesa;
		ofVec2f mesa_pos;

		string frases_ricos[5];
		bool hablando_rico;
		int que_rico;
		int cuantos_ricos;
		string ricos_echar[4];



		//Eventos

		void menu();
		void pantalla_principal();
		void escena_esclavos();
		void escena_modelos();
		void escenas_ricos();

		void keyReleased(int key);
		void mouseReleased(int x, int y, int button);
		
};