ss
/* Подключение шрифта CC Hammer Horror */
@font-face {
    font-family: 'CCHammerHorror';
    src: url('fonts/CC Hammer Horror.woff2') format('woff2'),
         url('fonts/CC Hammer Horror.woff') format('woff');
    font-weight: normal;
    font-style: normal;
    font-display: swap;
}

/* Переменные для цветов и шрифтов */
:root {
    --primary-bg: #0A0A2A;
    --secondary-bg: #1A1A4A;
    --neon-blue: #00FFFF;
    --neon-blue-light: #4DFFFF;
    --text-color: #E0E0E0;
    --light-gray: #B0B0B0;
    --dark-blue-gradient-start: #05051A;
    --dark-blue-gradient-end: #10052A;

    --font-primary: 'Montserrat', sans-serif;
    --font-secondary: 'CCHammerHorror', 'Oxanium', monospace;
}

/* Общие стили и сброс */
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

html {
    scroll-behavior: smooth;
}

body {
    font-family: var(--font-primary);
    background: linear-gradient(135deg, var(--dark-blue-gradient-start), var(--dark-blue-gradient-end));
    color: var(--text-color);
    line-height: 1.6;
    overflow-x: hidden;
    position: relative;
    cursor: none; /* Скрываем стандартный курсор */
}

/* Custom Cursor (возвращаем) */
.custom-cursor {
    width: 0.9375rem; /* 15px */
    height: 0.9375rem; /* 15px */
    background-color: var(--neon-blue);
    border-radius: 50%;
    position: fixed;
    pointer-events: none;
    z-index: 9999;
    transform: translate(-50%, -50%);
    transition: width 0.2s ease, height 0.2s ease, background-color 0.2s ease, transform 0.05s linear; /* Плавное движение, быстрый отклик */
    box-shadow: 0 0 0.625rem var(--neon-blue), 0 0 1.25rem var(--neon-blue-light); /* 10px, 20px */
    will-change: transform, width, height, background-color, box-shadow; /* Оптимизация */
}

.custom-cursor.active {
    width: 1.5625rem; /* 25px */
    height: 1.5625rem; /* 25px */
    background-color: var(--neon-blue-light);
    box-shadow: 0 0 1.25rem var(--neon-blue-light), 0 0 2.5rem var(--neon-blue); /* 20px, 40px */
}

.container {
    max-width: 1200px;
    margin: 0 auto;
    padding: 0 1.5rem;
}

a {
    color: var(--neon-blue);
    text-decoration: none;
    transition: color 0.3s ease, text-shadow 0.3s ease;
}

a:hover {
    color: var(--neon-blue-light);
    text-shadow: 0 0 0.5rem var(--neon-blue);
}

h1, h2, h3 {
    font-family: var(--font-secondary);
    font-weight: normal;
    margin-bottom: 1.25rem;
}

p {
    margin-bottom: 1rem;
}

.neon-text {
    color: var(--neon-blue);
    text-shadow: 0 0 0.3rem var(--neon-blue),
                 0 0 1rem var(--neon-blue),
                 0 0 1.5rem var(--neon-blue),
                 0 0 2.5rem rgba(0, 255, 255, 0.5);
}

.neon-icon {
    color: var(--neon-blue);
    text-shadow: 0 0 0.3rem var(--neon-blue),
                 0 0 0.6rem var(--neon-blue),
                 0 0 1.2rem rgba(0, 255, 255, 0.3);
}

.btn {
    display: inline-block;
    background: var(--neon-blue);
    color: var(--primary-bg);
    padding: 0.75rem 1.75rem;
    border-radius: 3rem;
    font-size: 1rem;
    font-weight: 600;
    text-transform: uppercase;
    transition: all 0.3s ease;
    border: none;
    cursor: none; /* Кнопки также не имеют стандартного курсора */
    box-shadow: 0 0 1rem rgba(0, 255, 255, 0.4);
    position: relative;
    overflow: hidden;
}

.btn::before {
    content: '';
    position: absolute;
    top: 50%;
    left: 50%;
    width: 0;
    height: 0;
    background: rgba(255, 255, 255, 0.2);
    border-radius: 50%;
    transform: translate(-50%, -50%);
    transition: width 0.4s ease, height 0.4s ease;
    z-index: 1;
}

.btn:hover::before {
    width: 200%;
    height: 200%;
}

.btn:hover {
    background: var(--neon-blue-light);
    transform: translateY(-0.1875rem) scale(1.02);
    box-shadow: 0 0 1.5rem rgba(0, 255, 255, 0.6), 0 0 2.5rem rgba(0, 255, 255, 0.3);
}
.btn i {
    position: relative;
    z-index: 2;
}

/* Header */
header {
    background: rgba(10, 10, 42, 0.9);
    padding: 0.9375rem 0;
    position: fixed;
    width: 100%;
    top: 0;
    left: 0;
    z-index: 1000;
    box-shadow: 0 0.125rem 0.9375rem rgba(0, 255, 255, 0.1);
    transition: background 0.3s ease, box-shadow 0.3s ease;
    backdrop-filter: blur(0.3125rem);
}

header.scrolled {
    background: rgba(10, 10, 42, 0.98);
    box-shadow: 0 0.25rem 1.25rem rgba(0, 255, 255, 0.2);
}

header .container {
    display: flex;
    justify-content: space-between;
    align-items: center;
}

.logo {
    font-family: var(--font-secondary);
    font-size: 2.2rem;
    font-weight: normal;
    color: var(--neon-blue);
    text-shadow: 0 0 0.5rem var(--neon-blue), 0 0 0.9375rem var(--neon-blue-light);
    transition: text-shadow 0.3s ease;
}

.logo:hover {
    text-shadow: 0 0 0.9375rem var(--neon-blue-light), 0 0 1.5625rem var(--neon-blue);
}

header nav ul {
    list-style: none;
    display: flex;
}

header nav ul li {
    margin-left: 1.875rem;
}

header nav ul li a {
    color: var(--text-color);
    font-weight: 600;
    padding: 0.3125rem 0;
    position: relative;
    text-transform: uppercase;
}

header nav ul li a::after {
    content: '';
    position: absolute;
    left: 0;
    bottom: -0.3125rem;
    width: 0;
    height: 0.125rem;
    background: var(--neon-blue);
    transition: width 0.3s ease;
    box-shadow: 0 0 0.5rem var(--neon-blue);
}

header nav ul li a:hover::after {
    width: 100%;
}

.header-btn {
    padding: 0.5rem 1.25rem;
    font-size: 0.9rem;
}

/* Hero Section */
.hero-section {
    height: 100vh;
    display: flex;
    justify-content: center;
    align-items: center;
    text-align: center;
    padding-top: 5rem;
    position: relative;
    overflow: hidden;
    z-index: 1;
}

.hero-section::before {
    content: '';
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background: url('https://source.unsplash.com/random/1920x1080/?cybernetic,brain') no-repeat center center/cover;
    opacity: 0.15;
    filter: grayscale(100%) brightness(50%) blur(0.1875rem);
    z-index: -1;
    animation: background-pan 30s linear infinite alternate;
}

@keyframes background-pan {
    0% { transform: scale(1) translate(0%, 0%); }
    100% { transform: scale(1.1) translate(-5%, -5%); }
}

.hero-section h1 {
    font-size: 4.5rem;
    margin-bottom: 1.5625rem;
    letter-spacing: 0.1875rem;
    line-height: 1.1;
}

.hero-subtitle {
    font-size: 1.6rem;
    color: var(--light-gray);
    margin-bottom: 2.5rem;
    font-weight: 300;
}

.hero-section .primary-btn {
    font-size: 1.2rem;
    padding: 0.9375rem 2.5rem;
    margin-top: 1.875rem;
}

.hero-section .primary-btn i {
    margin-right: 0.625rem;
}

/* Voice Wave Animation */
.voice-wave-container {
    display: flex;
    justify-content: center;
    align-items: center;
    height: 3.125rem;
    margin-top: 1.25rem;
    position: relative;
    padding: 0 1.25rem;
}

.voice-wave {
    width: 0.375rem;
    height: 0.1875rem;
    background-color: var(--neon-blue);
    margin: 0 0.1875rem;
    border-radius: 0.1875rem;
    animation: wave 1.5s infinite ease-in-out alternate;
    box-shadow: 0 0 0.4375rem var(--neon-blue), 0 0 0.9375rem var(--neon-blue-light);
    opacity: 0.7;
}

.voice-wave.delay-1 { animation-delay: 0.1s; }
.voice-wave.delay-2 { animation-delay: 0.2s; }
.voice-wave.delay-3 { animation-delay: 0.3s; }
.voice-wave.delay-4 { animation-delay: 0.4s; }

@keyframes wave {
    0% { height: 0.1875rem; transform: translateY(0); opacity: 0.5; }
    50% { height: 3.125rem; transform: translateY(-1.5625rem); opacity: 1; }
    100% { height: 0.1875rem; transform: translateY(0); opacity: 0.5; }
}

/* Section Padded General Styles */
.section-padded {
    padding: 6.25rem 0;
    text-align: center;
    background: var(--secondary-bg);
    margin: 3.75rem auto;
    border-radius: 1.25rem;
    box-shadow: 0 0 3.75rem rgba(0, 255, 255, 0.2);
    position: relative;
    overflow: hidden;
    max-width: 68.75rem;
    border: 0.0625rem solid rgba(0, 255, 255, 0.1);
}

.section-padded::before {
    content: '';
    position: absolute;
    top: -1.25rem;
    left: -1.25rem;
    right: -1.25rem;
    bottom: -1.25rem;
    background: linear-gradient(45deg, rgba(0,255,255,0.05) 0%, transparent 20%, transparent 80%, rgba(0,255,255,0.05) 100%);
    z-index: 0;
    pointer-events: none;
    animation: rotate-gradient 20s linear infinite;
}

@keyframes rotate-gradient {
    0% { transform: rotate(0deg); }
    100% { transform: rotate(360deg); }
}

.section-padded h2 {
    font-size: 3.5rem;
    margin-bottom: 2.5rem;
    text-transform: uppercase;
    position: relative;
    z-index: 1;
}

.bg-secondary {
    background: var(--primary-bg);
    box-shadow: 0 0 3.75rem rgba(0, 255, 255, 0.3);
}

/* About Section */
.about-content {
    display: flex;
    justify-content: center;
    align-items: center;
    gap: 3.75rem;
    text-align: left;
    max-width: 56.25rem;
    margin: 0 auto;
    position: relative;
    z-index: 1;
}

.about-text {
    flex: 1;
    font-size: 1.15rem;
    color: var(--light-gray);
}

.about-icon {
    flex-shrink: 0;
    width: 11.25rem;
    height: 11.25rem;
    display: flex;
    justify-content: center;
    align-items: center;
    background: rgba(0, 255, 255, 0.15);
    border-radius: 50%;
    border: 0.1875rem solid var(--neon-blue);
    box-shadow: 0 0 1.5625rem rgba(0, 255, 255, 0.6), inset 0 0 0.9375rem rgba(0, 255, 255, 0.4);
    animation: rotate 15s infinite linear;
    position: relative;
}
.about-icon::before {
    content: '';
    position: absolute;
    width: 80%;
    height: 80%;
    border-radius: 50%;
    border: 0.0625rem dashed var(--neon-blue-light);
    animation: rotate-reverse 10s infinite linear;
}

@keyframes rotate {
    from { transform: rotate(0deg); }
    to { transform: rotate(360deg); }
}
@keyframes rotate-reverse {
    from { transform: rotate(360deg); }
    to { transform: rotate(0deg); }
}

/* Features Grid */
.features-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(18.75rem, 1fr));
    gap: 2.5rem;
    margin-top: 2.5rem;
    position: relative;
    z-index: 1;
}

.feature-item {
    background: var(--secondary-bg);
    padding: 2.1875rem;
    border-radius: 0.9375rem;
    text-align: center;
    box-shadow: 0 0 1.25rem rgba(0, 255, 255, 0.1);
    transition: transform 0.3s ease, box-shadow 0.3s ease, border-color 0.3s ease;
    border: 0.0625rem solid rgba(0, 255, 255, 0.1);
    position: relative;
    overflow: hidden;
}

.feature-item::before {
    content: '';
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 0.3125rem;
    background: linear-gradient(to right, transparent, var(--neon-blue), transparent);
    transform: translateX(-100%);
    transition: transform 0.4s ease-out;
}

.feature-item:hover::before {
    transform: translateX(0%);
}

.feature-item:hover {
    transform: translateY(-0.75rem);
    box-shadow: 0 0 2.8125rem rgba(0, 255, 255, 0.5), inset 0 0 0.625rem rgba(0, 255, 255, 0.3);
    border-color: var(--neon-blue-light);
}

.feature-item i {
    font-size: 4rem;
    margin-bottom: 1.25rem;
}

.feature-item h3 {
    font-size: 1.8rem;
    color: var(--neon-blue-light);
    margin-bottom: 0.9375rem;
}

.feature-item p {
    color: var(--light-gray);
    font-size: 1.05rem;
}

/* Demo Section */
.demo-voice-area {
    margin-top: 3.125rem;
    display: flex;
    flex-direction: column;
    align-items: center;
    position: relative;
    z-index: 1;
}

.demo-btn {
    width: 8.75rem;
    height: 8.75rem;
    border-radius: 50%;
    display: flex;
    justify-content: center;
    align-items: center;
    font-size: 4rem;
    background: var(--neon-blue);
    color: var(--primary-bg);
    border: none;
    cursor: none; /* У кнопок также убираем стандартный курсор */
    box-shadow: 0 0 1.25rem rgba(0, 255, 255, 0.6), 0 0 2.5rem rgba(0, 255, 255, 0.4);
    transition: all 0.3s ease;
    position: relative;
    overflow: hidden;
}

/* Pulse animation for buttons */
@keyframes pulse {
    0% { transform: scale(1); box-shadow: 0 0 0 0 rgba(0, 255, 255, 0.4); }
    70% { transform: scale(1.1); box-shadow: 0 0 0 1.875rem rgba(0, 255, 255, 0); }
    100% { transform: scale(1); box-shadow: 0 0 0 0 rgba(0, 255, 255, 0); }
}

.pulse-effect {
    animation: pulse 2s infinite cubic-bezier(0.66, 0, 0, 1);
}

.demo-btn.listening {
    animation: listening-pulse 1.2s infinite ease-in-out;
    background-color: var(--neon-blue-light);
    box-shadow: 0 0 1.875rem var(--neon-blue-light), 0 0 3.75rem rgba(0, 255, 255, 0.5);
}

@keyframes listening-pulse {
    0% { transform: scale(1); opacity: 1; box-shadow: 0 0 0 0 rgba(0, 255, 255, 0.7); }
    50% { transform: scale(1.08); opacity: 0.9; box-shadow: 0 0 0 0.9375rem rgba(0, 255, 255, 0.3); }
    100% { transform: scale(1); opacity: 1; box-shadow: 0 0 0 0 rgba(0, 255, 255, 0.7); }
}

.demo-status {
    margin-top: 1.875rem;
    font-size: 1.4rem;
    color: var(--light-gray);
    font-family: var(--font-secondary);
    min-height: 2.5rem;
    display: flex;
    align-items: center;
    justify-content: center;
    padding: 0 1.25rem;
    text-shadow: 0 0 0.3125rem rgba(0, 255, 255, 0.3);
}

/* Contact Section */
.contact-info {
    margin-top: 2.5rem;
    font-size: 1.2rem;
    line-height: 2.2;
    color: var(--light-gray);
    position: relative;
    z-index: 1;
}

.contact-info p {
    margin-bottom: 0.625rem;
}

.contact-info .neon-icon {
    margin-right: 0.9375rem;
    font-size: 1.6rem;
}

.social-links {
    margin-top: 1.875rem;
}

.social-icon {
    font-size: 2.2rem;
    margin: 0 1.125rem;
    display: inline-block;
    transition: transform 0.3s ease, text-shadow 0.3s ease;
    color: var(--neon-blue);
    text-shadow: 0 0 0.5rem var(--neon-blue);
}

.social-icon:hover {
    transform: translateY(-0.5rem) scale(1.15);
    text-shadow: 0 0 0.9375rem var(--neon-blue-light), 0 0 1.5625rem var(--neon-blue);
}

/* Footer */
footer {
    background: var(--primary-bg);
    color: #888;
    padding: 2.5rem 0;
    text-align: center;
    border-top: 0.0625rem solid rgba(0, 255, 255, 0.1);
    position: relative;
    z-index: 1;
}

footer .container {
    display: flex;
    flex-direction: column;
    align-items: center;
}

.footer-links {
    margin-top: 0.9375rem;
}

.footer-links a {
    color: #888;
    margin: 0 0.9375rem;
    font-size: 0.95rem;
    text-transform: uppercase;
}

.footer-links a:hover {
    color: var(--neon-blue);
    text-shadow: 0 0 0.3125rem var(--neon-blue);
}

/* Background Grid Animation */
.background-grid {
    position: fixed;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    z-index: 0;
    background-image:
        linear-gradient(to right, rgba(0, 255, 255, 0.03) 1px, transparent 1px),
        linear-gradient(to bottom, rgba(0, 255, 255, 0.03) 1px, transparent 1px);
    background-size: 50px 50px;
    animation: grid-shift 30s linear infinite alternate;
}

@keyframes grid-shift {
    0% { background-position: 0 0; }
    100% { background-position: 50px 50px; }
}

/* Floating Particles (CSS-only for simple version, JS for more complex) */
.floating-particles-container {
    position: fixed;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    z-index: 0;
    pointer-events: none;
    overflow: hidden;
}

.floating-particle {
    position: absolute;
    background-color: var(--neon-blue-light);
    border-radius: 50%;
    box-shadow: 0 0 0.3125rem var(--neon-blue-light); /* 5px */
    filter: blur(0.0625rem); /* 1px */
    will-change: transform, opacity;
}

@keyframes float-particle {
    0% { transform: translate(0, 0) scale(1); opacity: var(--initial-opacity, 0.2); }
    50% { transform: translate(var(--offset-x, 0px), var(--offset-y, 0px)) scale(var(--scale, 1.1)); opacity: var(--peak-opacity, 0.7); }
    100% { transform: translate(0, 0) scale(1); opacity: var(--initial-opacity, 0.2); }
}


/* Кроссплатформенность: медиа-запросы с использованием rem */
@media (max-width: 992px) { /* 62em */
    body { cursor: default; } /* Возвращаем стандартный курсор на мобильных */
    .custom-cursor { display: none; } /* Скрываем кастомный курсор на мобильных */

    .hero-section h1 {
        font-size: 3.5rem;
    }
    .hero-subtitle {
        font-size: 1.3rem;
    }
    .about-content {
        flex-direction: column;
        gap: 1.875rem;
        text-align: center;
    }
    .about-icon {
        margin-top: 1.25rem;
        width: 9.375rem;
        height: 9.375rem;
    }
    .features-grid {
        grid-template-columns: repeat(auto-fit, minmax(17.5rem, 1fr));
        gap: 1.875rem;
    }
    .section-padded h2 {
        font-size: 2.8rem;
    }
}

@media (max-width: 768px) { /* 48em */
    header .container {
        flex-direction: column;
        gap: 0.9375rem;
    }
    header nav ul {
        flex-wrap: wrap;
        justify-content: center;
    }
    header nav ul li {
        margin: 0 0.9375rem 0.625rem 0.9375rem;
    }
    .header-btn {
        margin-top: 0.625rem;
    }

    .hero-section h1 {
        font-size: 2.8rem;
        letter-spacing: 0.125rem;
    }
    .hero-subtitle {
        font-size: 1.1rem;
    }
    .hero-section .primary-btn {
        font-size: 1rem;
        padding: 0.75rem 1.875rem;
    }
    .section-padded h2 {
        font-size: 2.2rem;
    }
    .features-grid {
        grid-template-columns: 1fr;
    }
    .logo {
        font-size: 1.8rem;
    }
}

@media (max-width: 480px) { /* 30em */
    .logo {
        font-size: 1.5rem;
    }
    header nav ul li {
        margin: 0 0.625rem 0.625rem 0.625rem;
    }
    .hero-section h1 {
        font-size: 2.2rem;
        letter-spacing: 0.0625rem;
    }
    .hero-subtitle {
        font-size: 0.9rem;
    }
    .section-padded h2 {
        font-size: 1.8rem;
    }
    .demo-btn {
        width: 6.25rem;
        height: 6.25rem;
        font-size: 3rem;
    }
    .demo-status {
        font-size: 1.2rem;
    }
    .contact-info, .footer-links {
        font-size: 0.9rem;
    }
    .container {
        padding: 0 1rem;
    }
}
        body { cursor: default; } /* Возвращаем стандартный курсор на мобильных */
        .custom-cursor { display: none; } /* Скрываем кастомный курсор на мобильных */
